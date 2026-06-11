#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
static const long double pi = 3.141592653589793;



int main(){
    string S, T;
    cin>>S>>T;
    ll SzS, SzT;
    SzS=S.size();
    SzT=T.size();
    vector<char> SS(SzS);
    vector<char> TT(SzT);
    rep(i, SzS){
        SS[i]=S.at(i);
    }
    rep(i,SzT){
        TT[i]=T.at(i);
    }
    sort(ALL(SS));
    sort(ALL(TT));
    reverse(ALL(TT));
    rep(i, SzS){
        if(SS[i]<TT[i]){
            cout<<"Yes"<<endl;
            return 0;
        }
        if(SS[i]>TT[i]){
            cout<<"No"<<endl;
            return 0;
        }
        if(i==SzT-1){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}
     