#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repp(i, n, m) for(int (i) = (n); (i) < (m); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define ldou long double
#define fi first
#define se second
#define setpre(x) std::cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ std::cout << " [LOGGER] " << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , "; logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 4005*4005;

/* ...o(^-^)o... */

int main(){
    string s; cin>>s;
    int n = s.size();

    if(s[n-1]=='1'){
        out(-1); return 0;
    }
    if(s[0]=='0'){
        out(-1); return 0;
    }

    vector<int> v;
    rep(k, n/2){
        if(s[k]!=s[n-k-2]){
            out(-1); return 0;
        }
        if(k>0 && s[k]=='1') v.push_back(k+1);
    }
    v.push_back(n);
    reverse(all(v));

    int x = 1, y = 2;
    rep(i, v.size()-1){
        int s = v[i], t = v[i+1];
        rep(j, s-t-1){
            cout<<x<<" "<<y<<endl;
            y++;
        }
        cout<<x<<" "<<y<<endl;
        x = y; y++;
    }
    while(y <= n){
        cout<<x<<" "<<y<<endl;
        y++;
    }
}