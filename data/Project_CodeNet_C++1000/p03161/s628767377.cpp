#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define pb push_back
const int maxn = 10000;
const int INF32 = 1'050'000'000;
const long long INF64 = 4'000'000'000'000'000'000;
const int MOD7 = 1'000'000'007;
const int MOD9 = 1'000'000'009;
const int mod = MOD7;

void ERROR(int num) { cout << "ERROR" << num << endl; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,1,-1};


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    rep(i,N) cin >> h[i];
    vector<int> dp(N+5, INF32);
    dp[0] = 0;

    for(int i = 1; i < N; i++){
        for(int k= 1; k <= K; k++){
            if(i-k>=0) dp[i] = min(dp[i], dp[i-k]+abs(h[i]-h[i-k]));
        }
    }

    cout << dp[N-1] << endl;
 }