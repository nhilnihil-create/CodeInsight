#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;


ll binary_search(
    ll lo, ll hi, function<bool(ll)> is_ok,
    bool maximize
){
    while(lo < hi){
        if(maximize){
            const ll mid = (lo + hi + 1) / 2;
            if(is_ok(mid)){
                lo = mid;
            }else{
                hi = mid - 1;
            }
        }else{
            ll mid = (lo + hi - 1) / 2;
            if(is_ok(mid)){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
    }
    return lo;
}


int main(){
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    string t, d;
    REP(i, q){
        char ti, di;
        cin >> ti >> di;
        t.push_back(ti);
        d.push_back(di);
    }

    const auto simulate = [&](ll i) -> ll {
        REP(j, q){
            if(t.at(j) == s.at(i)){
                if(d.at(j) == 'L'){
                    i--;
                }else{
                    i++;
                }
            }
            if(i < 0){
                return -1;
            }else if(i >= n){
                return 1;
            }
        }
        return 0;
    };

    ll left = 0;
    if(simulate(0) == -1){
        left = 1 + ::binary_search(
            0, n - 1, [&](ll x) -> bool { return simulate(x) == -1; }, true);
    }

    // right
    ll right = n;
    if(simulate(n - 1) == 1){
        right = ::binary_search(
            0, n - 1, [&](ll x) -> bool { return simulate(x) == 1; }, false);
    }

    cout << right - left << endl;

    return 0;
}
