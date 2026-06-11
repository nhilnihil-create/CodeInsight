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
    ll N, C;
    cin >> N >> C;
    vector<ll> s(N),t(N),c(N);
    map<ll,ll> mps[31],mpt[31];
    rep(i,N){
        cin >> s[i] >> t[i] >> c[i];
        mps[c[i]][s[i]]++;
        mpt[c[i]][t[i]]++;
        if(mpt[c[i]][s[i]] > 0){
            mpt[c[i]][s[i]]--;
            mps[c[i]][s[i]]--;
        }
        if(mps[c[i]][t[i]] > 0){
            mpt[c[i]][t[i]]--;
            mps[c[i]][t[i]]--;
        }
    }
    vector<ll> S(100010);
    REP(i,1,C+1){
        for(auto& p:mps[i]){
            if(p.second > 0){
                S[p.first] += p.second;
            }
        }
    }
    REP(i,1,C+1){
        for(auto& p:mpt[i]){
            if(p.second > 0){
                S[p.first+1] -= p.second;
            }
        }
    }
    /*rep(i,N){
        S[s[i]-1]++;
        S[t[i]+1]--;
    }*/
    //PR(S,100);
    rep(i,100009){
        S[i+1] += S[i];
    }
    ll ans = 0;
    rep(i,100010){
        cmax(ans, S[i]);
    }
    //PR(S,100);
    cout << ans << endl;
}
