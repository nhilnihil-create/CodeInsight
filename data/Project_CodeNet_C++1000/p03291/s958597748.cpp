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

vector<ll> thr(100001);

ll three(ll n){
    if(n < 0) return 0;
    return thr[n];
}

int main(){
    StarBurstStream

    string s;
    cin >> s;
    int n = s.size();

    thr[0] = 1;
    for(int i = 1; i <= 100000; i++) thr[i] = thr[i - 1] * 3 % MOD;

    int Q = 0;
    for(char i : s) Q += (i == '?');

    ll ans = 0;
    ll a = 0, ab = 0;
    ll q = 0;
    ll qb = 0, aq = 0;
    ll qq = 0;
    for(int i = 0; i < n; i++){
//        cerr << i << " " << s[i] << " " << a << " " << ab << " " << q << " " << qb << " " << aq << " " << qq << "\n";
        if(s[i] == 'A'){
            a++;
            a %= MOD;
        }
        else if(s[i] == 'B'){
            ab += a;
            qb += q;
            ab %= MOD;
            qb %= MOD;
        }
        else if(s[i] == 'C'){
            ans += ab * three(Q) % MOD;
            ans += aq * three(Q - 1) % MOD;
            ans += qb * three(Q - 1) % MOD;
            ans += qq * three(Q - 2) % MOD;
            ans %= MOD;
        }
        else{
            ans += ab * three(Q - 1) % MOD;
            ans += qb * three(Q - 2) % MOD;
            ans += aq * three(Q - 2) % MOD;
            ans += qq * three(Q - 3) % MOD;
            ans %= MOD;
            aq += a;
            qq += q;
            q++;
            aq %= MOD;
            qq %= MOD;
            q %= MOD;
        }
    }

    cout << ans << "\n";

    return 0;
}