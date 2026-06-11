#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    string S,T;
    cin >> S >> T;
    ll N = S.size();
    vector<ll> v(26,-1), u(26,-1);
    bool flag = true;
    rep(i,N){
        ll s = S[i]-'a';
        ll t = T[i]-'a';
        if(v[s] == -1){
            v[s] = t;
        }else{
            if(v[s] != t){
                flag = false;
                break;
            }
        }
        if(u[t] == -1){
            u[t] = s;
        }else{
            if(u[t] != s){
                flag = false;
                break;
            }
        }
    }
    cout << (flag?"Yes":"No") << endl;
}