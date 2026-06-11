#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)
#define mp make_pair

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int32 k;
    cin >> k;
    vector<int32> a(k);
    REP(i,k)cin >> a[i];
    if(a[k-1] != 2){
        cout << -1 << endl;
        return 0;
    }
    int32 mn = 2;
    FORR(i,k-2,0){
        int32 k = (mn - 1) / a[i] + 1;
        // while(a[i] * k < mn)k++;
        mn = a[i] * k;
    }
    int32 mx = 3;
    FORR(i,k-2,0){
        int32 k = mx / a[i] + 1;
        // while(a[i] * k <= mx)k++;
        mx = a[i] * k - 1;
    }
    if(mn > mx){
        cout << -1 << endl;
    }else{
        cout << mn << " " << mx << endl;
    }
    return 0;
}