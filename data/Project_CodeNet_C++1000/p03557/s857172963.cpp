#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main(){
    LL n;
    vector<LL> a;
    vector<LL> b;
    vector<LL> c;
    LL tmp_a;
    LL tmp_b;
    LL tmp_c;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp_a;
        a.push_back(tmp_a);
    }
    for(int i=0; i<n; i++){
        cin >> tmp_b;
        b.push_back(tmp_b);
    }
    for(int i=0; i<n; i++){
        cin >> tmp_c;
        c.push_back(tmp_c);
    }

    vector<LL> b_num(n, 0);
    vector<LL> c_num(n, 0);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int idx=0;
    for(int i=0; i<n; i++){
        if(a[i]<b[idx]){
            b_num[idx]++;
        }else{
            while(a[i]>=b[idx] && idx<n-1){
                idx++;
                b_num[idx]=b_num[idx-1];
            }
            if(a[i]<b[idx]){
                b_num[idx]++;
            }
        }
    }
    while(idx<n-1){
        idx++;
        b_num[idx]=b_num[idx-1];
    }

    idx=0;
    for(int i=0; i<n; i++){
        if(b[i]<c[idx]){
            c_num[idx]+=b_num[i];
        }else{
            while(b[i]>=c[idx] && idx<n-1){
                idx++;
                c_num[idx]=c_num[idx-1];
            }
            if(b[i]<c[idx]){
                c_num[idx]+=b_num[i];
            }
        }
    }
    while(idx<n-1){
        idx++;
        c_num[idx]=c_num[idx-1];
    }

    LL ans=0;

    //for(int i=0; i<n; i++){
    //    cout << b_num[i] << endl;
    //}

    //cout << "test" << endl;

    //for(int i=0; i<n; i++){
    //    cout << c_num[i] << endl;
    //}

    for(int i=0; i<n; i++){
        ans+=c_num[i];
    }

    cout << ans << endl;

    return 0;
}
