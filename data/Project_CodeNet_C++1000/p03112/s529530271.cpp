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

int main(){
    ll A,B,Q;
    cin >> A >> B >> Q;
    vector<ll> s(A),t(B),x(Q);
    rep(i,A){
        cin >> s[i];
    }
    rep(i,B){
        cin >> t[i];
    }
    rep(i,Q){
        cin >> x[i];
    }
    /*vector<Pll> P(A+B);
    rep(i,A){
        P[i] = Pll(s[i],0);
    }
    rep(i,B){
        P[A+i] = Pll(t[i],1);
    }
    sort(P.begin(), P.end());
    */
    rep(i,Q){
        ll ans = 1e18;
        ll si = lower_bound(s.begin(),s.end(),x[i]) - s.begin();
        ll ti = lower_bound(t.begin(),t.end(),x[i]) - t.begin();
        if(si > 0 && ti > 0){
            cmin(ans, abs(x[i] - min(s[si-1], t[ti-1])));
        }
        if(si > 0 && ti < B){
            cmin(ans, min(abs(x[i] - s[si-1]), abs(x[i] - t[ti]))*2 + max(abs(x[i] - s[si-1]), abs(x[i] - t[ti])));
        }
        if(ti > 0 && si < A){
            cmin(ans, min(abs(x[i] - s[si]), abs(x[i] - t[ti-1]))*2 + max(abs(x[i] - s[si]), abs(x[i] - t[ti-1])));
        }
        if(si < A && ti < B){
            cmin(ans, abs(x[i] - max(s[si], t[ti])));
        }
        cout << ans << endl;
    }
}

