#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
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
    ll H,W,N;
    cin >> H >> W >> N;
    ll sr,sc;
    cin >> sr >> sc;
    sr--;sc--;
    string S,T;
    cin >> S >> T;
    vector<Pll> SP(N+1);
    vector<Pll> GP(N+1);
    SP[N] = Pll(0,0); 
    GP[N] = Pll(H,W); 
    bool flag = true;
    for(ll i=N-1;i>=0;i--){
        SP[i] = SP[i+1];
        GP[i] = GP[i+1];
        if(i != N-1){
            if(T[i] == 'L'){
                GP[i].se = min(GP[i].se+1LL,W);                
            }else if(T[i] == 'R'){
                SP[i].se = max(SP[i].se-1LL,0LL);                
            }else if(T[i] == 'U'){
                GP[i].fi = min(GP[i].fi+1LL,H);                
            }else if(T[i] == 'D'){
                SP[i].fi = max(SP[i].fi-1LL,0LL);                
            }
        }
        if(S[i] == 'L'){
            SP[i].se++;
        }else if(S[i] == 'R'){
            GP[i].se--;
        }else if(S[i] == 'U'){
            SP[i].fi++;
        }else if(S[i] == 'D'){
            GP[i].fi--;   
        }
        if(SP[i].fi < GP[i].fi && SP[i].se < GP[i].se){
            flag = true;
            continue;
        }else{
            flag = false;
            break;
        }
        //cout << SP[i].fi << " " << SP[i].se << " a " << GP[i].fi << " " << GP[i].se << endl;
    }
    if(SP[0].fi <= sr && sr < GP[0].fi && SP[0].se <= sc && sc < GP[0].se && flag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
