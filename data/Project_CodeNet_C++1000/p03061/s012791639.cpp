#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define vint(a,n) vint a(n); rep(i, n) cin >> a[i];
#define vll(a,n) vll a(n); rep(i, n) cin >> a[i];
#define ALL(n) begin(n),end(n)
#define RALL(n) rbegin(n),rend(n)
#define MOD (1000000007)
#define INF (2e9)
#define INFL (2e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
using vint=vector<int>;
using vll=vector<ll>;
using vbool=vector<bool>;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

vint primes;
map<int, int> sum;

template<class T>bool isprime(T n){
if(n==2) return true;
if(!(n&1)) return false;
for(T i=3; i*i<=n; i+=2){if(n%i==0) return false;}
return true;}

template<class T>
map<T, int> prime_factorize(T n){
    map<T, int> m;
    T t = n;
    for(int i=2; i*i<=t; i++){
        int k=i;
        while(t!=1&&t%i==0){
            m[k]++;
            k*=i;
            t/=i;
        }
    }
    if(t!=1) m[t]++;
    return m;
}

int main()
{
    int n; cin >> n;
    vint(a, n);

    map<int, int> m[n];
    vint v;
    rep(i, n){
        m[i] = prime_factorize(a[i]);
        // cout << a[i] << ":";
        for(auto p: m[i]){
            // cout << " " << p.first;
            sum[p.first]++;
        }
        // pr("");
    }

    for(auto p: sum) {
        v.push_back(p.first);
        if(isprime(p.first)) primes.push_back(p.first);
    }

    // prvec(v);
    // prvec(primes);
    int ans = 1;

    rep(i, n){
        int t = 1;
        for(int p: primes){
            int k = p;

            // cout << k << " " << sum[k]-m[i][k] << endl;
            if(sum[k]-m[i][k]<n-1) continue;
            while(sum[k*p] > 0 && sum[k*p]-m[i][k*p]>=n-1){
                k*=p;
            }
            t *= k;
        }
        chmax(ans, t);
    }
    pr(ans);
    return 0;}