#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

ll N,A,B,C;
vector<ll> l(8);
ll dfs(ll cur, ll a, ll b, ll c){
    if(cur == N){
        if(min(min(a,b),c) > 0){
            return abs(A-a) + abs(B-b) + abs(C-c) -30;
        }
        return 1e18;
    }
    ll ret0 = dfs(cur+1, a,b,c);
    ll ret1 = dfs(cur+1, a + l[cur], b, c)+10;
    ll ret2 = dfs(cur+1, a, b + l[cur], c)+10;
    ll ret3 = dfs(cur+1, a, b, c+l[cur])+10;
    return min(min(ret0,ret1),min(ret2,ret3));
}


int main(){
    cin >> N >> A >> B >> C;
    rep(i,N){
        cin >> l[i];
    }
    cout << dfs(0,0,0,0) << endl;
}

