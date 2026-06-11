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
const int MAX = 300005;

/* ...o(^-^)o... */

void solve(vector<bool> used){
    for(int k=1; k<=30000; k++){
        if(used[k]) outs(k);
    }
    out("");
}

int main(){
    int n; cin>>n;
    vector<bool> used(30005);
    used[2]=true; used[5]=true; used[63]=true;
    if(n==3){
        solve(used); return 0;
    }
    used[20]=true;
    if(n==4){
        solve(used);
        return 0;
    }
    used[30]=true;
    if(n==5){
        solve(used);
        return 0;
    }
    
    fill(all(used), false); int sum = 0, last;
    for(int k = 2; k <= 30000; k++){
        if(n==0 || k%6==1 || k%6==5) continue;
        used[k] = true; sum += k; last = k;
        n--;
    } last++;

    if(sum%6==2){
        used[8] = false;
        while(last%6!=0) last++;
        used[last] = true;
    }
    else if(sum%6==3){
        used[9] = false;
        while(last%6!=0) last++;
        used[last] = true;
    }
    else if(sum%6==5){
        used[9] = false;
        while(last%6!=4) last++;
        used[last] = true;
    }
    solve(used);
}
