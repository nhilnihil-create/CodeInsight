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
    string s;
    cin >> s;
    ll N = s.size();
    string S="";
    rep(i,N-1){
        if(s.substr(i,2) == "BC"){
            S.push_back('D');
            i++;
        }else{
            S.push_back(s[i]);
        }
    }
    ll M = S.size();
    ll ans = 0;
    ll cnt = 0;
    rep(i,M){
        if(S[M-1-i] == 'D'){
            cnt++;
        }else if(S[M-1-i] == 'A'){
            ans += cnt;
        }else{
            cnt = 0;
        }
    }
    cout << ans << endl;

}