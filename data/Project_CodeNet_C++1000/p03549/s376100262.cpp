#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<double> VD;
typedef vector<double> VL;
typedef vector<string> VS;
typedef vector<PLL> VP;
typedef vector<ll> VLL;
const static int INF = 1000000000;
const static int MOD = 1000000007;
#define rep(i,n) for (ll i=0; i<(ll)(n); i++)
#define repd(i,n) for (ll i=n-1; i>=0; i--)
#define rept(i,m,n) for(ll i=m; i<n; i++)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define PF push_front
#define PB push_back
#define SORT(V) sort((V).begin(), (V).end())
#define RVERSE(V) reverse((V).begin(), (V).end())
#define paired make_pair
#define PRINT(V) for(auto v : (V)) cout << v << " "
int ctoi(char c) { if (c >= '0' && c <= '9') { return c - '0'; } return 0; } //charを整数に
void cum_sum(int N,vector<double> a, vector<double> &s){ for(int i=0; i<N; i++){ s[i+1]=s[i]+a[i];}}
//空白文字も入力 getline(cin, S);
//桁数指定 setprecision
// 累積和 for (int i = 0; i < N; ++i) s[i+1] = s[i] + a[i];

int main()
{
    int N, M;
    cin >> N >> M;
    int ans=1;
    rep(i,M){
        ans*=2;
    }
    cout << (1900*M+100*(N-M))*ans << endl;
}