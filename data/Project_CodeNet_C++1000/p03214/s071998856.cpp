#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;


int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n){
        cin >> a.at(i);
    }
    const ll s = accumulate(ALL(a), 0LL);
    ll ans = 0;
    REP(i, n){
        if(abs(a.at(i) * n - s) < abs(a.at(ans) * n - s)){
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
