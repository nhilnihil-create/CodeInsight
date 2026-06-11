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
const ll inf = 2e9 + 5;
double PI = 3.14159265358979323846;

void solve() {

    int n;
    cin >> n;
    double p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<vector<double>> dp(n + 1, vector<double> (n + 1,0));

    // dp[i][j] = probability of getting j heads from i coins

    dp[0][0] = 1.0;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= i;j++){
            // dp[i][j] = (probab. of getting head on ith coin and getting j-1 heads in i-1 coins)
            //  + (probab. of getting tail on ith coin and getting j heads in i-1 coins)
            dp[i][j] = dp[i-1][j]*(1-p[i-1]) + (j == 0 ? 0 : dp[i-1][j-1]*p[i-1]);
        }
    }



    double ans = 0;
    for(int heads = 0;heads <= n;heads++){
        int tails = n-heads;
        if(heads > tails){
            ans+=dp[n][heads];
        }
    }
    cout << fixed << setprecision(10) << ans << endl;


}

int32_t main()
{
    IOS
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
