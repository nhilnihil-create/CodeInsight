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

int b[25];
 
int32_t main()
{
    fast;
    int n, m, c, res = 0, sum = 0, val; cin >> n >> m >> c;
    For(i, 0, m) cin >> b[i];
    For(i, 0, n) {
        sum = 0;
        For(j, 0, m) {
            cin >> val;
            sum += val * b[j];
        }
        if(sum + c > 0) res++;
    }

    cout << res << "\n";
    
    return 0;
}