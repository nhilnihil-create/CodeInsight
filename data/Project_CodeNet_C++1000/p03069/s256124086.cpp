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
#define RALL(n) rbegin(n),end(n)
#define MOD (1000000007)
#define INF (2e9)
#define INFL (2e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
using vint=vector<int>;
using vll=vector<ll>;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int n; string s;
    cin >> n >> s;

    vint w(n), b(n);
    if(s[0]=='#') b[0]++;
    rep(i, n-1){
        b[i+1] += b[i];
        if(s[i+1]=='#') b[i+1]++;
    }

    if(s[n-1]=='.') w[n-1]++;
    for(int i=n-1; i>0; i--){
        w[i-1] += w[i];
        if(s[i-1]=='.') w[i-1]++;
    }

    int ans = INF;
    rep(i, n+1){
        if(i==0) chmin(ans, w[i]);
        else if(i==n) chmin(ans, b[i-1]);
        else chmin(ans, b[i-1] + w[i]);
    }
    pr(ans);
    return 0;}