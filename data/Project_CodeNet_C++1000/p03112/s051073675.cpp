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
    ll A, B, Q;
    cin>>A>>B>>Q;
    vector<ll> S(A), T(B);
    rep(i, A){
        cin>>S[i];
    }
    rep(i, B){
        cin>>T[i];
    }
    rep(i, Q){
        ll X;
        cin>>X;
        auto itrS=lower_bound(ALL(S), X);
        auto itrT=lower_bound(ALL(T), X);
        ll D, DD, C, CC;
        if(*itrS==X){
            D=X;
            DD=X;
        }
        else if(itrS==S.begin()){
            D=-1*INF;
            DD=S[0];
        }
        else if(itrS==S.end()){
            D=S[A-1];
            DD=INF;
        }
        else{
            DD=*itrS;
            itrS--;
            D=*itrS;
        }
        if(*itrT==X){
            C=X;
            CC=X;
        }
        else if(itrT==T.begin()){
            C=-1*INF;
            CC=T[0];
        }
        else if(itrT==T.end()){
            C=T[B-1];
            CC=INF;
        }
        else{
            CC=*itrT;
            itrT--;
            C=*itrT;
        }
      	//cout<<D<<" "<<C<<" "<<" "<<CC<<" "<<DD<<endl;
        vector<ll> W(6);
        W[0]=(CC+X-2*D);
      	W[1]=(2*CC-X-D);
        W[2]=(DD+X-2*C);
      	W[3]=(2*DD-X-C);
        W[4]=X-min(C, D);
        W[5]=max(CC, DD)-X;
        sort(ALL(W));
        cout<<W[0]<<endl;
        
        
    }

}
     