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
    string S;
    cin >> S;
    bool ok = 1;
    if(S[0] != 'A')ok = 0;
    if(S[1]-'a'<0 || S[S.size()-1] - 'a'<0)ok = 0;
    sort(ALL(S));
    S[0]+='a' - 'A';
    if(S[1] != 'C'){
        ok = 0;
    }else{
        S[1]+='a' - 'A';
    }
    REP(i,S.size()){
        if(S[i]-'a'<0)ok = 0;
    }
    cout << (ok ? "AC" : "WA") << "\n";
}