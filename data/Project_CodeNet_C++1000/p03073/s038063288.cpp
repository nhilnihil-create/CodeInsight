#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    string s;
    cin >> s;

    int cnt0=0,cnt1=0;
    for(int i=0;i<s.size();i++){
        if(i%2==0){
            if(s.at(i)!='0') cnt0++;
        }else{
            if(s.at(i)!='1') cnt0++;
        }
    }

    for(int i=0;i<s.size();i++){
        if(i%2==0){
            if(s.at(i)=='0') cnt1++;
        }else{
            if(s.at(i)=='1') cnt1++;
        }
    }

    cout << min(cnt0,cnt1) << endl;
}