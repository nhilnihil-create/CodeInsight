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
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
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
    ll n,z,w;
    cin>>n>>z>>w;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    auto dp=make_vec<ll>(n+10,2);
    for(int i = n - 1; i >= 0; i--) {
        dp[i][0]=-LINF;
        ll y=(i==0 ? w : a[i-1]);
        chmax(dp[i][0],abs(y-a[n-1]));
        for(int j = i+1; j < n; j++) {
            chmax(dp[i][0],dp[j][1]);
        }

        dp[i][1]=LINF;
        ll x=(i==0 ? z : a[i-1]);
        chmin(dp[i][1],abs(x-a[n-1]));
        for(int j = i+1; j < n; j++) {
            chmin(dp[i][1],dp[j][0]);
        }
    }
    cout<<dp[0][0]<<endl;

}

