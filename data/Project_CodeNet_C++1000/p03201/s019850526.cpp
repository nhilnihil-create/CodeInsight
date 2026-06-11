#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)
typedef long long ll;
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

inline ll add(ll x, ll y) {return (x+y)%MOD;}
inline ll mul(ll x, ll y) {return (x*y)%MOD;}
inline ll sub(ll x, ll y) {
    ll res = x - y;
    if(res < 0) res += MOD;
    return res;
}

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    REP(i,N) cin >> A[i];
    sort(all(A),greater<ll>());
    multiset<ll> not_used;
    for(auto x:A) not_used.insert(x);
    int ans = 0;
    for(auto x:A) {
        if(not_used.find(x)==not_used.end()) continue;
        ll large = x;
        auto itr1 = not_used.find(large);
        not_used.erase(itr1);
        ll tmp = 1;
        while(tmp<=x) tmp*=2;
        ll small = tmp-x;
        if(not_used.find(small)!=not_used.end()){
            ans++;
            auto itr2 = not_used.find(small);
            not_used.erase(itr2);
        }
    }
    cout << ans << endl;
    return 0;
}