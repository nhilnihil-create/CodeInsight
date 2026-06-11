#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());

template<class T> inline void chmin(T& a, T b){
    if (a > b){
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b){
    if (a < b){
        a = b;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    ll N;
    string S;
    ll Q;
    cin >> N >> S >> Q;
    vector<ll> k(N);
    REP(i,Q)cin >> k[i];
    vector<ll> cmr(0);
    vector<ll> dm(0);
    vector<ll> c(0);
    vector<ll> d(0);
    ll nowm = 0;
    REP(i,N){
        if(S[i] == 'M'){
            nowm++;
        }else if(S[i] == 'D'){
            d.pb(i);
            dm.pb(nowm);
        }else if(S[i] == 'C'){
            c.pb(i);
            if(c.size() != 1){
                cmr.pb(cmr[cmr.size()-1] + nowm);
            }else{
                cmr.pb(nowm);
            }
        }
    }
    REP(i,Q){
        ll answer = 0;
        if(c.size() == 0 || d.size() == 0){
            cout << 0 << "\n";
            continue;
        }
        REP(l,d.size()){
            ll idxin = distance(c.begin(), lower_bound(ALL(c),d[l]));
            ll idxax = distance(c.begin(), lower_bound(ALL(c),d[l]+k[i]));
            if(idxax != 0 && idxin != c.size()){
                answer += cmr[idxax-1]-(idxin == 0 ? 0 : cmr[idxin-1]) - (idxax - idxin)*dm[l];
            }
            // cout << (idxax == 0 ? 0 : cmr[idxax-1]) <<" "<< (idxin == 0 ? 0 : cmr[idxin-1]) <<" "<< idxax <<" "<< idxin <<" "<< dm[l] <<" "<<cmr[idxax-1]-(idxin == 0 ? 0 : cmr[idxin-1]) - (idxax - idxin)*dm[l]<< "\n";
        }
        cout << answer << "\n";
    }
}