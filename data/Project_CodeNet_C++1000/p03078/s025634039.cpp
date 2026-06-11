#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll X,Y,Z,K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    map<ll,ll> mp;
    rep(i,X){
        cin >> A[i];
    }
    rep(i,Y){
        cin >> B[i];
    }
    rep(i,Z){
        cin >> C[i];
    }
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());
    priority_queue<Pll> que;
    vector<ll> ans;
    que.push(Pll(A[0]+B[0]+C[0], 0));
    mp[0]++;
    rep(i,K){
        Pll t = que.top();
        que.pop();
        ans.push_back(t.fi);
        ll a = ((t.se >> 0) & ((1LL << 10) - 1));
        ll b = ((t.se >> 10) & ((1LL << 10) - 1));
        ll c = ((t.se >> 20) & ((1LL << 10) - 1));
        //cout << a << " " << b <<" " << c << endl;
        if(!mp.count((t.se + 1)) && a < X-1){
            que.push(Pll(A[a+1]+B[b]+C[c], t.se + 1));
            mp[t.se + 1]++;
        }
        if(!mp.count(t.se + (1LL << 10LL)) && b <Y-1){
            que.push(Pll(A[a]+B[b+1]+C[c], t.se + (1LL << 10)));
            mp[t.se + (1LL << 10LL)]++;
        }
        if(!mp.count(t.se + (1LL << 20LL)) && c < Z-1){
            que.push(Pll(A[a]+B[b]+C[c+1], t.se + (1LL << 20)));
            mp[t.se + (1LL << 20LL)]++;
        }
    }
    rep(i,K){
        cout << ans[i] << endl;
    }
}