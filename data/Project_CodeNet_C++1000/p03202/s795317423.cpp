#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    ll N; cin >> N;
    if (N==1){
        cout << 1 << endl;
        return 0;
    }
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    rep(i,N-1){
        if (A[i+1]<=A[i]) break;
        if (i==N-2){
            cout << 1 << endl;
            return 0;
        }
    }
    ll lb=1,ub=N+1;
    map<ll,ll> m;
    while(ub-lb>1){
        ll mid=(ub+lb)/2;
        m.clear();
        bool ok=true;
        rep(i,N-1){
            if (A[i+1]<=A[i]){
                auto itr=m.upper_bound(A[i+1]);
                m.erase(itr,m.end());
                ll now=A[i+1];
                ++m[now];
                while(m[now]>=mid){
                    m.erase(now);
                    --now;
                    if (now==0){
                        ok=false;
                        break;
                    }
                    ++m[now];
                }
                if (!ok) break;
            }
        }
        if (ok) ub=mid;
        else lb=mid;
    }
    cout << ub << endl;
}