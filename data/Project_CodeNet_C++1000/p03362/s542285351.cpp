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
template<class T>bool isprime(T n){
if(!(n&1)) return false;
for(T i=3; i*i < n; i+=2){
if(n%i==0) return false;
}
return true;
}

#define N 100000
bitset<N> primes;
void sieve(){  // nが素数ならばbitset[n]==1
    primes[0]=1; primes[1]=1;
    for(int i=4; i<N; i+=2){
        primes |= (bitset<N>(1)<<i);
    }
    for(int i=3; i<N; i+=2){
        if(primes[i]) continue;
        if(!isprime(i)) continue;
        for(int j=i*3; j<N; j+=2*i){
            primes |= (bitset<N>(1)<<j);
        }
    }
    primes = ~primes;
}

int main()
{
    sieve();
    int n ;cin >> n;
    vint v;
    FOR(i, 3, 55556){
        if(primes[i]){
            if((i-1)%3!=0) continue;
            int k = (i-1)/3;
            if(k%10==0) v.push_back(i);
            if(v.size()==n) break;
        }
    }
    prvec(v);
    // pr(v.size());
    return 0;}