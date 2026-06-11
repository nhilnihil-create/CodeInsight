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
    vector<pair<int,int>> res;
    if(N%2==1) {
        FOR(i,1,N) FOR(j,i+1,N+1) {
            if(i+j != N) res.push_back(make_pair(i,j));
        }
    }
    else {
        FOR(i,1,N) FOR(j,i+1,N+1) {
            if(i+j != N+1) res.push_back(make_pair(i,j)); 
        }
    }
    cout << res.size() << endl;
    for(auto p:res) cout << p.first << " " << p.second << endl;
    return 0;
}