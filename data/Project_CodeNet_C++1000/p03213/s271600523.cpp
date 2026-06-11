#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
using Graph = vector<vector<ll> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

map<ll, ll> prime;

void prime_factorize(ll N) {
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; 

        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        prime[a]+=ex;
    }

    if (N != 1) prime[N]++;
    return;
}

int main(){
    ll n;
    cin >> n;
    for(int i=1;i<=n;i++){
        prime_factorize(i);
    }
    ll ans = 0;

    ll c74=0;
    ll c2=0;
    ll c24=0;
    ll c4=0;
    ll c14=0;

    
    for(auto it=prime.begin();it!=prime.end();it++){
        if(it->second>1)c2++;
        if(it->second>3)c4++;
        if(it->second>13)c14++;
        if(it->second>23)c24++;       
        if(it->second>73)c74++;
    }
    ans += c74;
    ans += c24*(c2-1);
    ans += c14*(c4-1);
    ans += (c2-2)*(c4)*(c4-1)/2;
    cout<<ans<<endl;

}
