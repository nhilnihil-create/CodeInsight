#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double 
const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;


typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef unordered_map<int,int> mii;
typedef unordered_map<char,int> mci;
typedef unordered_map<string,int> msi;

#define pb push_back
#define f first
#define s second 
 

void solve() {
    int n,k; cin>>n>>k;
    vi A(n);
    bool ans;
    for(int i=0;i<n;i++) cin>>A[i];
    vvb dp(k+1,vb(2,0)) ;
    //dp[0][0] = dp[0][1] = 0;
    for(int i=1;i<=k;i++) {
        ans = 1;
        for(int j=0;j<n;j++) {
            if(i>=A[j]) {
                ans = ans && dp[i-A[j]][1];
            }
        }
        dp[i][0] = 1 - ans;
        ans = 1;
        for(int j=0;j<n;j++) {
            if(i>=A[j]) {
                ans = ans && dp[i-A[j]][0];
            }
        }
        dp[i][1] = 1 - ans;
    }
    if(dp[k][0]) {
        cout<<"First\n";
    }
    else {
        cout<<"Second\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //#ifdef LOCAL
      //  freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif

    int tc; tc=1;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}