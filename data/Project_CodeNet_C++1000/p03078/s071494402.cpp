#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
#define int long long
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf 1e18
#define For(i,a,b) for (int i = a; i < b; i++)
#define Rep(i,a,b) for (int i = a; i <= b; i++)
#define ps(x,y) fixed << setprecision(y) << x 
#define pb push_back 
#define mp make_pair 

int a[1005], b[1005], c[1005];
vi ans;
 
int32_t main()
{
    fast;
    int x, y, z, k; cin >> x >> y >> z >> k;
    For(i, 0, x) cin >> a[i];
    For(i, 0, y) cin >> b[i];
    For(i, 0, z) cin >> c[i];

    sort(a, a+x, greater<int>());
    sort(b, b+y, greater<int>());
    sort(c, c+z, greater<int>());

    For(i, 0, x) {
        For(j, 0, y) {
            For(m, 0, z) {
                if((i+1) * (j+1) * (m+1) <= k) ans.pb(a[i] + b[j] + c[m]);
                else break;
            }
        }
    }

    sort(ans.begin(), ans.end(), greater<int> ());
    For(i, 0, k) cout << ans[i] << "\n";
    
    return 0;
}