#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using P = pair<ll,ll>;
constexpr ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define eb emplace_back
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
    cout<<fixed<<setprecision(12);
    vector<ll> C(9);
    REP(i,9)cin >> C[i];
    bool ok = 0;
    for(int i = -101;i < 101;i++){
        for(int l = -101;l < 101;l++){
            for(int k = -101; k < 101;k++){
                if(C[0]-i == C[1]-l&&C[0]-i == C[2]-k){
                    if(C[3]-i == C[4]-l&&C[3]-i == C[5]-k){
                        if(C[6]-i == C[7]-l&&C[6]-i == C[8]-k){
                            ok = 1;
                        }
                    }
                }
            }
        }
    }
    cout << (ok ? "Yes" : "No") << "\n";
}