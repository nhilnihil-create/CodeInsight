#include <bits/stdc++.h>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long int;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1e9;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
int main(){
    string s;
    cin >> s;
    int a = s.length();
    int l,r,ans,b = s[a/2];
    if (a%2){
        ans = a/2+1;
        l = a/2-1;
        r = a/2+1;
    }
    else{
        ans = a/2;
        l = a/2-1;
        r = a/2;
    }
    while(l >= 0 && s[l] == b && s[r] == b){
        ans += 1;
        l--;
        r++;
    }
    PRINT(ans);
}