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
const ll INF = 1e11;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
int main(){
    ll n,k,t,d;
    P sushi[100005];
    bool neta[100005] = {0};
    cin >> n >> k;
    rep(i,n){
        cin >> t >> d;
        sushi[i] = P(d,t);
    }
    sort(sushi,sushi+n,greater<P>());
    priority_queue<P,vector<P>,greater<P>> q1;
    priority_queue<P> q2;
    ll ans[100005] = {0};
    ll x = 0,c = 0;
    rep(i,k){
        if (neta[sushi[i].second]) q1.push(sushi[i]);
        else{
            neta[sushi[i].second] = true;
            x++;
        }
        ans[0] += sushi[i].first;
    }
    rep(i,k,n){
        if (!neta[sushi[i].second]){
            q2.push(sushi[i]);
            neta[sushi[i].second] = true;
        }
    }
    while(!q2.empty() && !q1.empty()){
        ans[c+1] = ans[c]+q2.top().first-q1.top().first;
        q1.pop();q2.pop();
        c++;
    }
    ll a = 0;
    rep(i,c+1){
        chmax(a,ans[i]+(x+i)*(x+i));
    }
    PRINT(a);
}