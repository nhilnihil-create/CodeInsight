#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define fi first
#define se second
#define setpre(x) cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ cout << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 100005;

/* ...o(^-^)o... */
int c[13];

int main(){
    int n; cin >> n;
    vector<int> d;
    rep(i, n){
        int x; cin >> x; c[x]++;
    }

    lint M = pow(2, 11);
    int res = 0;
    rep(k, M){
        int l = k;
        vector<int> e;
        if(c[0]) break;
        e.push_back(0); e.push_back(24);
        if(c[12]) e.push_back(12);

        bool brk = false;
        repn(i, 11){
            if(!c[i]) continue;
            int m = l % 2; l /= 2;
            if(c[i] == 1){
                if(m == 0) e.push_back(i);
                else if(m == 1) e.push_back(24-i);
            }
            else if(c[i] == 2){
                e.push_back(i); e.push_back(24-i);
            }
            else{ brk = true; break; }
        }
        if(brk) continue;

        sort(all(e));
        int gap = 30;
        rep(i, e.size()-1) gap = min(gap, abs(e[i]-e[i+1]));
        res = max(res, min(gap, 24-gap));
    }
    out(res);
}
