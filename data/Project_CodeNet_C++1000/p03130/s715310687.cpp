#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE cout << -1 << endl;return 0
#define Endl endl

signed main(void){
    int a[4]={},t;
    REP(i,6){
        cin >> t;
        a[t-1]++;
    }
    sort(a,a+4);
    if(a[3]!=3){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}

