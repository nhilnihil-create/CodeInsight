#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ar array
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod = 1e9 + 7;
const ll inf = 2e15 + 5;
double PI = 3.14159265358979323846;

void solve() {

    int n;
    cin >> n;
    vl a(n+1);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    vvl dp(n+1,vl(n+1,0));

    // dp[i][j] = minimum possible in range [i....j]

    for(int i = 2;i <= n;i++){
        int r = 1;
        int c = i;
        while(c <= n){
           
            ll temp = inf;
            ll s = 0;
            for(int j = r;j <= c;j++){
                s+= a[j];
            }
            for(int j = r;j < c;j++){
                temp = min(temp,dp[r][j]+dp[j+1][c]+s);
            }
            dp[r][c] = temp;
            r++;c++;
        }
    }

    cout << dp[1][n] << endl;


}

int32_t main()
{
    IOS
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
