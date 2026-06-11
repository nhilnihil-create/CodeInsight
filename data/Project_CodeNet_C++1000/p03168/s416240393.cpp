#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<utility>
#include<cmath>
#include<cstring>
#include<stack>
#include<queue>
#include<tuple>
#include<map>
#include <numeric>

using namespace std;
#define etm cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define ull unsigned long long int
#define pb push_back
#define pii pair<int , int>
#define pdd pair<double , double>
#define pll pair<ll,ll>
#define vpl vector<pll>
#define vll vector<ll>
#define vb vector<bool>
#define vd vector<double>
#define vs vector<string>
#define mi map<int, int>
#define mull map<ull, ull>
#define stp setprecision(20)

#define fo(i,start,end) for(ll i=start;start<end?i<end:i>end;start<end?i+=1:i-=1)
#define MOD 1000000007
#define ld long double
#define inf 1e18
#define mp  make_pair
#define v_pll vector<pair<ll,ll>>
#define vv_pll vector<vector<pair<ll,ll>>>
#define v_vll vector<vector<ll>>
#define all(x) x.begin(),x.end()
#define all_b(x) x.rbegin(),x.rend()
#define fi first
#define se second
#define test ll T;cin>>T;while(T--)
#define show(w,size) for(ll i=0;i<size;i++) cout<<w[i]<<" ";
#define u_mll unordered_map<ll,ll>
#define mll   map<ll,ll>
#define count_bit __builtin_popcount // Number of set bits .
#define count_zero_st __builtin_clz//no of zeros in starting
#define count_zero_end __builtin_ctz//no of zeros in end
#define in insert
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
#define db(...)                 __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
ll gcd(ll a,ll b){if(a<b)return gcd(b,a);else if(b==0)return a;else return gcd(b,a%b);}
ll isPrime(ll n){ll p=(ll)sqrt(n);fo(i,2,p+1) if(n%i==0) return 0;return 1;}// return 1 if prime
ll pow(ll b,ll e){if(e==0)return 1;else if(e%2==0){ll a=pow(b,e/2);return a*a;}else {ll a=pow(b,e/2);return b*a*a;}}
ll pow_m(ll x,ll y,ll m=MOD){x=x%m;ll res=1;while(y){if(y&1)res=res*x;res%=m;y=y>>1;x=x*x;x%=m;}return res;}
ll modInverse(ll a, ll m) { return pow_m(a, m-2, m);}
ll max(ll a,ll b){if(a>=b)return a;else return b;}
ll min(ll a,ll b){if(a<=b)return a;else return b;}

bool t_won(ll a){
    return (a&(a-1)) == 0;
}

int main(){
    fastio;
    int n;
    scanf("%d", &n);
    // dp[heads]
    // if we had i tosses, then tails=i-heads
    vector<double> dp(n + 1);
    // dp[i] - p-bility that there are i heads so far
    dp[0] = 1;
    for(int coin = 0; coin < n; ++coin) {
        double p_heads;
        scanf("%lf", &p_heads);
        for(int i = coin + 1; i >= 0; --i) {
            dp[i] = (i == 0 ? 0 : dp[i-1] * p_heads) + dp[i] * (1 - p_heads);
        }
    }
    double answer = 0;
    for(int heads = 0; heads <= n; ++heads) {
        int tails = n - heads;
        if(heads > tails) {
            answer += dp[heads];
        }
    }
    printf("%.10lf\n", answer);

    return 0;
}