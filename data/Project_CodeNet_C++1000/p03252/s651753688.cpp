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

int main(){
    ll N;
    string S,T;
    cin >> S >> T;
    N = S.size();
    //map<ll,ll>mp[26], trans;
    vector<ll> v(26,-1), u(26,-1);
    rep(i,N){
        ll s = S[i] - 'a';
        ll t = T[i] - 'a';
        if(v[s] != -1 || u[t] != -1){
            if(v[s] != t || u[t] != s){
                cout << "No" << endl;
                return 0;
            }
        }else{
            v[s] = t;
            u[t] = s;
        }
        //if(S[i] != T[i]){
        //mp[S[i]-'a'][T[i]-'a']++; 
        //mp[T[i]-'a'][S[i]-'a']++;
            //trans[S[i]] = T[i];
            //trans[T[i]] = S[i];
        //}
    }
    /*bool flag = true;
    rep(i,26){
        if(mp[i].size() > 1){
            flag = false;
            break;
        }
    }
    /*
    if(flag){
        rep(i,N){
            S[i] = trans[S[i]];
        }
    }
    flag = (S == T);*/

    cout << "Yes" << endl;
}