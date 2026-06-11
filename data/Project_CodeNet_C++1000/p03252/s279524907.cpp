#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
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
    string S,T;
    cin >> S >> T;
    ll N = S.size();
    vector<ll> v(26,-1),u(26,-1);
    rep(i,N){
        //if(S[i] == T[i])continue;
        if(v[S[i]-'a'] == -1 && u[T[i]-'a'] == -1){
            v[S[i]-'a'] = T[i] - 'a';
            u[T[i]-'a'] = S[i] - 'a';
            continue;
        }
        if(v[S[i]-'a'] == T[i] - 'a' && u[T[i]-'a'] == S[i] - 'a'){
            continue;
        }
        /*
        if(v[S[i]-'a'] == -1){
            v[S[i]-'a'] = T[i] - 'a';
            continue;
        }
        if(u[T[i]-'a'] == -1){
            u[T[i]-'a'] = S[i] - 'a';
            continue;
        }
        /*if(v[S[i]-'a'] == -1 || u[T[i]-'a'] == -1){
            v[S[i]-'a'] = T[i] - 'a';
            u[T[i]-'a'] = S[i] - 'a';
            continue;
        }else{*/            
        cout << "No" << endl;
        return 0;
        //}
    }
    cout << "Yes" << endl;
}