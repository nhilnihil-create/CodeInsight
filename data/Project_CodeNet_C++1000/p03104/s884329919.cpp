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

int main()
{
    ll a, b; cin >> a >> b;
    a--;
    ll ansa=0, ansb=0;

    ll bi = 1;
    rep(i, 63){
        ll diva = a / bi;
        ll divb = b / bi;
        bi *= 2;
        ll mda = a % bi;
        ll mdb = b % bi;

        if(i==0){
            if((((diva+1)/2)%2)==1) ansa += 1;
            if((((divb+1)/2)%2)==1) ansb += 1;
            continue;
        }

        if(diva%2==1 && mda%2==0) ansa += (1LL<<i);
        if(divb%2==1 && mdb%2==0) ansb += (1LL<<i);
    }

    ll ans;
    // pr(ansa);
    // pr(ansb);
    if(a==-1) ans = ansb;
    else ans = ansa^ansb;

    pr(ans);

    // pr(ans^a);
    return 0;}