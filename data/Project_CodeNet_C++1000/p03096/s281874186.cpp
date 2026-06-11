#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(std::unique(all(x)), x.end());
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=acos(-1);
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    int n;
    cin>>n;
    vector<int> c(n+1);
    c[0]=-1;
    for(int i = 1; i <= n; i++) {
        cin>>c[i];
    }

    vector<ll> dp(n+10);
    vector<ll> cnt(200100);
    dp[0]=1;
    for(int i = 1; i <= n; i++) {
        dp[i]+=dp[i-1];
        if(c[i-1]==c[i]) continue;
        dp[i]+=cnt[c[i]];
        cnt[c[i]]+=dp[i-1];
        
        dp[i]%=MOD;
        cnt[c[i]]%=MOD;
    }
    cout<<dp[n]<<endl;
}

