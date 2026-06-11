#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N;
    cin >> N;

    vector<ll> A(N);
    FOR(i, 0, N){
        cin >> A.at(i);
    }
    ll sum = 0;
    for(ll a : A){
        sum += a;
    }

    bitset<2000*2000+1> dp;
    dp[0] = 1;
    for(ll a : A){
        dp |= (dp<<a); // ここのコストも2000
    }
    dp[0] = 0;

    vector<ll> V;
    FOR(i, 0, 2000*2000+1){
        if(dp[i]==1) V.push_back(i);
    }

    // ll target = sum/2; // これはだめ
    ll target = (sum+1)/2;

    auto it = lower_bound(ALL(V), target);
    p(*it);
    
    return 0;
}