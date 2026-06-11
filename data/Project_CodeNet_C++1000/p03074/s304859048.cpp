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
    ll N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<ll> v;
    ll cnt = 0;
    ll now = 1;
    rep(i,N){
        if(S[i] - '0' == now){
            cnt++;
        }else{
            v.push_back(cnt);
            cnt = 0;
            now = (now==0?1:0);
            i--;
        }
    }
    v.push_back(cnt);
    if(now==0){
        v.push_back(0);
    }
    //PR(v,v.size());
    ll M = v.size();
    ll ans = 0;
    ll tmp = 0;// v[0];
    ll r = 0;
    rep(l,M){
        if(l > r) r = l;
        while(r < M && r < l+K*2+1 ){
            tmp += v[r];
            r++;
            /*if(r < M && r-l < K*2+1){
                tmp += v[r];
                r++;
            }*/
        }
        //cout << tmp << endl;
        cmax(ans, tmp);
        if(l<r){
            tmp -= v[l];
        }
        l++;
        if(l<r){
            tmp -= v[l];
        }
        //tmp -= v[l];
    }
    cout << ans << endl;
}