#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
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
    cout<<fixed<<setprecision(12);
    vector<ll> NAME(5);
    ll N;
    cin >> N;
    vector<string> S(N);
    REP(i,N)cin >> S[i];
    REP(i,N){
        if(S[i][0] == 'M'){
            NAME[0]++;
        }else if(S[i][0] == 'A'){
            NAME[1]++;
        }else if(S[i][0] == 'R'){
            NAME[2]++;
        }else if(S[i][0] == 'C'){
            NAME[3]++;
        }else if(S[i][0] == 'H'){
            NAME[4]++;
        }
    }
    ll ans = 0;
    for(ll i = 0;i < 5;i++){
        for(ll l = i+1;l < 5;l++){
            for(ll k = l+1;k < 5;k++){
                ans += NAME[i]*NAME[l]*NAME[k];
            }
        }
    }
    cout << ans << "\n";
}