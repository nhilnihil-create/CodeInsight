#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define GET_ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))
#define LL long long
#define VI vector<int>
#define VL vector<LL>
#define VII vector< vector<int> >
#define VLL vector< vector<LL> >
#define VS  vector<string>
#define VSS vector< vector<string> >
#define PII pair<int,int>
#define PIS pair<int,string>
#define PSI pair<string,int>
#define PLL pair<LL,LL>
const LL MOD = 1000000007;
const LL INF = 1e16;
LL facctorialMethod(int k);
int main(){
    LL count = 0,log_count;
    string n,n_at;
    cin >> n;
    n_at = n.substr(0,1);
//    cout << "n.substr(0,1) :" << n.substr(0,1) << endl;
    for(int i = 1; i < 4; i++) {
//        cout << "n.substr(i,1) :" << n.substr(i,1) << endl;
        if(n_at == n.substr(i,1)){
            count++;
            if(count >= 2) {
            break;
            }
        }else{
            count = 0;
        }
        n_at = n.substr(i,1);
    }
//    cout << "count :" << count << endl;
    if(count >= 2) {
        cout << "Yes" << endl;        
    }else{
        cout << "No" << endl;
    }


    return 0;
}

LL facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i){
        sum *= i;
    }
    return sum;
}
