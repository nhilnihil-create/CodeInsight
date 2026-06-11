#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << "\t|";
    __f(comma + 1, args...);
}

#define print(x) for(auto it : x) cout<< it << ' '; cout << '\n';
typedef long long ll;
typedef unsigned long long ull;
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))

const int MOD = 1e9 + 7;
ll mod(ll a) { return (ll) (a % MOD + MOD) % MOD; }
ll mul(ll a, ll b) { return (ll) mod(mod(a) * mod(b));}

int a[100];
int dp[100006];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[0] = 0;
    for (int i = 1; i <= 100005; i++) {
        dp[i] = 0;
        for (int j = 0; j < n; j++) {
            int el = a[j];
            if ((i - el >= 0) && (!dp[i - el])) {
                dp[i] = 1;
                break;
            }
        }
    }
    cout << (dp[k] ? "First\n" : "Second\n") ;
    return 0;
}
