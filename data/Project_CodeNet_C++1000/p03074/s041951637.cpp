#include <iostream>
//#include <set>
//#include <map>
//#include <iomanip>
//#include <algorithm>
//#include <numeric>
#include <queue>
//#include <stack>
//#include <math.h>
//#include <vector>
#include <string>
//#include <list>
//#include <deque>
//#include <unordered_map>
typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main() {
    int n;
    int k;
    vector<int> zero_start;
    vector<int> one_start;
    int ans=0;
    string s;
    cin >> n >> k;
    cin >> s;

    if(n==1){
        if(s[0]=='0'){
            zero_start.push_back(0);
        }else{
            one_start.push_back(0);
        }
    }
    for(int i=1; i<n; i++){
        if(s[i-1]=='0' && s[i]=='1'){
            one_start.push_back(i);
        }else if(i==1 && s[i-1]=='1'){
            one_start.push_back(i-1);            
        }
        if(s[i-1]=='1' && s[i]=='0'){
            zero_start.push_back(i);
        }else if(i==1 && s[i-1]=='0'){
            zero_start.push_back(i-1);       
        }
    }

    //cout << zero_start.size() << " " << one_start.size() << endl;
    //cout << zero_start[1] << " " << one_start[1] << endl;
    int tmp;
    if(one_start.size()==0 || zero_start.size()==0){
        ans = n;
    }else{
        if(one_start[0]<zero_start[0]){
            //cout << "test0" << endl;
            if(one_start.size()>k){
                for(int i=0; i<one_start.size()-k; i++){
                    if(zero_start.size()>i+k){
                        tmp=zero_start[i+k]-one_start[i];
                    }else{
                        tmp=n-one_start[i];
                    }
                    //cout << one_start[i] << " " << one_start[i+k] << " " << tmp << endl;
                    if(tmp>ans){
                        ans=tmp;
                    }
                }
                tmp=n-one_start[one_start.size()-k];
                //cout << one_start[one_start.size()-k] << " " << tmp << endl;
                if(tmp>ans){
                    ans=tmp;
                }
            }else{
                ans=n;
            }
        }else{
            //cout << "test" << endl;
            if(zero_start.size()>k){
                ans=zero_start[k]-zero_start[0];
                for(int i=1; i<zero_start.size()-k; i++){
                    tmp=zero_start[i+k]-one_start[i-1];
                    if(tmp>ans){
                        ans=tmp;
                    }
                }
                tmp=n-one_start[zero_start.size()-k-1];
                //cout << tmp << endl;
                if(tmp>ans){
                    ans=tmp;
                }                
            }else{
                ans=n;
            }
        }
    }

    cout << ans << endl;

    return 0;
}