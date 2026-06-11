//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int l;
    cin >> l;

    int n = __lg(l) + 1;
    vector<pair<pii, int>> ans;
    vector<int> ans2;
    int t = l;
    for(int i = 1; i < n; i++){
//        cerr << i << " " << t << "\n";
        if(t % 2) ans2.eb(i), t--;
        ans.eb(mp(mp(i, i + 1), 1 << (i - 1)));
        ans.eb(mp(mp(i, i + 1), 0));
        t /= 2;
    }

    t = 1 << (n - 1);
    for(int i : ans2){
        ans.eb(mp(mp(i, n), t));
        t += 1 << (i - 1);
    }

    cout << n << " " << ans.size() << "\n";
    for(auto i : ans){
        cout << i.F.F << " " << i.F.S << " " << i.S << "\n";
    }

    return 0;
}