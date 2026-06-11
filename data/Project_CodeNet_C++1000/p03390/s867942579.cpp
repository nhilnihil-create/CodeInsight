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
    int Q; cin >> Q;
    while(Q--) {
        ll A, B; cin >> A >> B;
        if(A==B) {
            cout << 2*(A-1) << endl;
            continue;
        }
        if(A>B) swap(A,B); // A<=B
        ll C = A*B;
        ll ub = A + B - 1;
        ll lb = A - 1;
        ll mid;
        while(ub-lb>1) {
            mid = (ub + lb) / 2;
            if(((mid+1)/2)*(mid+1-(mid+1)/2)<C) lb = mid;
            else ub = mid;
        }
        cout << lb-1 << endl;
    }
    return 0;
}