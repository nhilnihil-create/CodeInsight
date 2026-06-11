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

template <class T = int>T in(){
    T x;
    cin >> x;
    return (x);
}

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
    int N = in(),C = in();
    vector<vector<int>> cost(C,vector<int>(C));
    REP(i,C){
        REP(l,C){
            cost[i][l] = in();
        }
    }
    vector<int> ze(C);
    vector<int> on(C);
    vector<int> tw(C);
    REP(i,N){
        REP(l,N){
            if((i+l)%3 == 0)ze[in()-1]++;
            if((i+l)%3 == 1)on[in()-1]++;
            if((i+l)%3 == 2)tw[in()-1]++;
        }
    }
    ll answer = INT32_MAX;
    vector<ll> zes(C);
    vector<ll> ons(C);
    vector<ll> tws(C);
    REP(i,C){
        REP(l,C){
            zes[i] += ze[l]*cost[l][i];
        }
    }
    REP(i,C){
        REP(l,C){
            ons[i] += on[l]*cost[l][i];
        }
    }
    REP(i,C){
        REP(l,C){
            tws[i] += tw[l]*cost[l][i];
        }
    }
    REP(i,C){
        REP(l,C){
            if(i == l)continue;
            REP(j,C){
                if(i == j)continue;
                if(l == j)continue;
                chmin(answer,zes[i] + ons[l] + tws[j]);
            }
        }
    }
    cout << answer << "\n";
}