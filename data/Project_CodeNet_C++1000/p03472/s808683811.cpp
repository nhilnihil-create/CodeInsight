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
    ll N,H;
    cin >> N >> H;
    vector<pair<ll,ll>> sword(N);
    vector<pair<ll,ll>> ss(N);
    REP(i,N){
        cin >> sword[i].S >> sword[i].F;
        ss[i].F = sword[i].S;
        ss[i].S = sword[i].F;
    }
    sort(ALL(ss),greater<>());
    ll zan = ss[0].F;
    ll chinpo = ss[0].S;
    REP(i,N){
        if(ss[0].F == ss[i].F)chmin(chinpo,ss[i].S);
    }
    REP(i,N){
        if(sword[i].S == zan&&sword[i].F == chinpo){
            sword[i].F = 0;
            sword[i].S = 0;
            break;
        }
    }
    ll count = 1;
    ll last = max(zan,chinpo);
    sort(ALL(sword),greater<>());
    ll inq = 0;
    while(H > last){
        if(inq < N){
            H -= max(sword[inq].F,zan);
            if(H <= 0)count--;
        }else{
            ll cc = 0;
            cc = (H - last+zan-1)/zan;
            if(H - cc*zan > 0){
                count += cc;
            }else{
                count += cc-1;
            }
            break;
        }
        count++;
        inq++;
    }
    cout << count << "\n";
}