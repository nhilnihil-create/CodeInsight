#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(ll i = a; i < (n); ++i)
#define repD(i, a, n) for(ll i = a; i > (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (long long) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
// #define mp make_pair
#define pb push_back
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
const long double PI = 3.141592653589793238462643383;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<double> vd;
typedef vector<pii> vii;
long long Ceil(long long a, long long b){
    if(a%b==0) return a/b;
    else return (a/b)+1;
}
ll p=1000000007;
float E = 0.00000000000001;
ll power(ll x, ll y){
    if(y==0){
        return 1;
    }
    if(y%2==0){
        ll q=power(x,y/2);
        q=q%p;
        return (q*q)%p;
    }
    ll q=power(x,y/2);
    q=q%p;
    return ((x%p)*((q*q)%p))%p; 
}
bool isPowerOfTwo (long long x)  
{  
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));  
}  

long long int gcd(long long int a, long long int b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a); 
}
long long int mod(long long int a, long long int b) {
    long long int ret = a%b; return ret>=0? ret: ret+b; 
}
bool rec(int k, int turn, vector<vector<int>> &dp, vector <int> &vec){
    if(dp[k][turn] != -1)
        return dp[k][turn];
    int n = vec.size();
    bool win = false;
    for(int i = 0 ; i < n ; i++){
        if(vec[i] == k){
            dp[k][turn] = 1;
            return true;
        }
        if(vec[i] < k)
            win = win | (!rec(k-vec[i], 1-turn, dp, vec));
    }
    if(win)
        dp[k][turn] = 1;
    else
        dp[k][turn] = 0;
    return win;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> vec(n);
        for(auto &x:vec)
            cin>>x;
        if(*min_element(vec.begin(), vec.end()) > k){
            cout<<"Second"<<endl;
            continue;
        }
        vector <vector<int>> dp(k+1, vector<int>(2, -1));
        // if(rec(k, 0, dp, vec))
        //     cout<<"First"<<endl;
        // else
        //     cout<<"Second"<<endl;
        for(int i = 1 ; i <= k ; i++){
            for(int player = 0 ; player <= 1 ; player++){
                int win = 0;
                for(int j = 0 ; j < n ; j++){
                    if(vec[j] == i){
                        dp[i][player] = 1;
                        break;
                    }
                    if(vec[j] < i)
                        win = win | !dp[i-vec[j]][1-player];
                }
                if(dp[i][player] == -1)
                    dp[i][player] = win;
            }
        }
        // dbg(dp);
        if(dp[k][0])
            cout<<"First"<<endl;
        else
            cout<<"Second"<<endl;
    }
    return 0;
}
