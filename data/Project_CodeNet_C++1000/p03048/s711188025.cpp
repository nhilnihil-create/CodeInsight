#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int cntr = n / r + 1, cntg = n / g + 1;
    int ans = 0;
    rep(i, cntr) {
        rep(j, cntg) {
            int value = n - r * i - g * j;
            if(value >= 0 && value % b == 0) ans++; 
        }
    } 
    cout << ans << endl;

    return 0;
}