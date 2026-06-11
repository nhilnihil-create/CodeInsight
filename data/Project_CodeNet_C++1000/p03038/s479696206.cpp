#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<ll> VLL;
typedef vector<PLL> VP;
const static int INF = 1000000000;
const static int MOD = 1000000007;
const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
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
//charを整数に
int ctoi(char c) { if (c >= '0' && c <= '9') { return c - '0'; } return 0; }
// 累積和 for (int i = 0; i < N; ++i) s[i+1] = s[i] + a[i]; 
void cum_sum(int N,vector<double> a, vector<double> &s){ for(int i=0; i<N; i++){ s[i+1]=s[i]+a[i];}}
//ユークリッドの控除法
ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
//最小公倍数
ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b; // Be careful not to overflow
}
//素数判定
bool is_prime(long long n) {
    if (n <= 1) return false;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p == 0) return false;
    }
    return true;
}
int getdigit(ll num){
    unsigned digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}
//空白文字も入力 getline(cin, S);
//桁数指定 setprecision

int main()
{
    ll N, M;
    cin >> N >> M;
    VLL A(N);
    rep(i,N){
        cin >> A[i];
    }
    vector<pair<ll,ll>> F;
    ll res=0;
    rep(i,M){
        ll b, c;
        cin >> b >> c;
        res+=b;
        F.PB(make_pair(c,b));
    }
    if(res<=N){
        res=res;
    }
    else{
        res=N;
    }
    sort(all(F));
    reverse(all(F));
    VLL S;
    bool judge=false;
    while(1){
        for(int i=0; i<M; i++){
            for(int j=0; j<F[i].S; j++){
                S.PB(F[i].F);
                if(S.size()==res){
                    judge=true;
                    break;
                }
            }
            if(judge) break;
        }
        if(judge) break;
    }
    //cout << S.size() << endl;
    sort(all(A));
    reverse(all(A));
    ll counter_a=0;
    ll counter_s=0;
    ll sum=0;
    rep(i,N){
        if(A[counter_a]>=S[counter_s]){
            sum+=A[counter_a];
            counter_a++;
            continue;
        }
        if(A[counter_a]<=S[counter_s] && counter_s<S.size()){
            sum+=S[counter_s];
            counter_s++;
            continue;
        }
    }
    cout << sum << endl;
}