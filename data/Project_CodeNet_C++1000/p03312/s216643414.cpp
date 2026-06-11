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

int32 n;
int64 a[200000+1];

int32 binarySearch(int32 l, int32 r, int32 x, int32 y){
    while(r - l >= 3){
        int32 nx = (l + r) / 2;
        if(a[nx] - a[x] == a[y] - a[nx]){
            l = nx;
            r = nx;
        }else if(a[nx] - a[x] < a[y] - a[nx]){
            l = nx;
        }else{
            r = nx;
        }
    }
    int64 mn = abs(a[y] - 2 * a[r] + a[x]);
    int32 retval = r;
    FOR(i,l,r){
        int64 diff = abs(a[y] - 2 * a[i] + a[x]);
        if(diff < mn){
            mn = diff;
            retval = i;
        }
    }
    return retval;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    a[0] = 0;
    REP(i,n){
        int32 ai;
        cin >> ai;
        a[i+1] = a[i] + ai;
    }
    // int32 y = binarySearch(2, n - 2, 0, n);
    // int32 x = binarySearch(1, y - 1, 0, y);
    // int32 z = binarySearch(y + 1, n - 1, y, n);
    // cout << x << " " << y << " " << z << endl;
    // vector<int32> p(4);
    // p[0] = a[x];
    // p[1] = a[y] - a[x];
    // p[2] = a[z] - a[y];
    // p[3] = a[n] - a[z];
    // REP(i,4)cout << p[i] << " ";
    // cout << endl;
    // sort(ALL(p));
    // ANS(p[3] - p[0]);
    int64 ans = LLINF;
    FOR(y,2,n-1){
        int32 x = binarySearch(1, y - 1, 0, y);
        int32 z = binarySearch(y + 1, n - 1, y, n);
        vector<int32> p(4);
        p[0] = a[x];
        p[1] = a[y] - a[x];
        p[2] = a[z] - a[y];
        p[3] = a[n] - a[z];
        sort(ALL(p));
        ans = min(ans, p[3] - p[0]);
    }
    ANS(ans);
    return 0;
}