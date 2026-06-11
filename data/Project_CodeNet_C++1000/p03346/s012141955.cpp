#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 1000000000000000000;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

int main(){
    ll N;cin >> N;
    vector<ll> A(N);
    map<ll,ll> mp;
    rep(i,N){
        cin >> A[i];
        mp[A[i]] = mp[A[i]-1] + 1;
    }
    ll ans = 0;
    auto begin = mp.begin(),end = mp.end();
    for(auto itr = begin;itr != end;itr++){
        //cout << itr ->first << ' ' << itr ->second << endl;
        ans = max(itr->second,ans);
    }
    cout << N - ans << endl;
}