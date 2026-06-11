#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) (a).begin(), (a).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rc(s) return cout<<s,0
#define pi pair <int, int>
#define sz(x) (int)((x).size())
#define int long long


const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

const ll inf = 0x3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 3e3 + 11;
const ll INF64 = 3e18 + 1;
const double lil = 0.0000000000001;

int n, dp[N][N], pref[N], l, r;

string s;


int32_t main(){
ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;

    cin >> s;

    dp[1][1] = 1;

    for(int i = 2; i <= n; i++){

        pref[0] = 0;

        for(int j = 1; j <= n; j++){
            pref[j] = (dp[i-1][j] + pref[j - 1] + mod) % mod;
        }

        for(int j = 1; j <= i; j++){

            if(s[i - 2] == '<'){
                l = 1; r = j - 1;
            }else{
                l = j; r = n;
            }

            if(l > r)continue;

            dp[i][j] = (pref[r] - pref[l - 1] + mod) % mod;
        }

    }

    int ans = 0;

    for(int i = 1; i <= n; i++)ans += (dp[n][i] + mod) % mod;

    rc((ans + mod) % mod);


}