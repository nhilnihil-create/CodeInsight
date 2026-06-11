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
    string s;
    ll x,y;
    cin >> s >> x >> y;
    map<ll,ll> LX, LY;
    LX[0] = 1;
    LY[0] = 1;
    vector<ll> v,h;
    ll N = s.size();
    ll cnt = 0;
    bool st = 0;
    bool init = 1;
    rep(i,N){
        map<ll,ll> tm;
        if(s[i] == 'T'){
            if(st==0){
                for(auto&e:LX){
                    tm[e.fi+cnt] = 1;
                    if(init)continue;
                    tm[e.fi-cnt] = 1;
                }
                LX = tm;
                h.push_back(cnt);
                init = 0;
            }else{
                for(auto&e:LY){
                    tm[e.fi+cnt] = 1;
                    tm[e.fi-cnt] = 1;
                }
                LY = tm;
                v.push_back(cnt);
            }
            st = !st;
            cnt = 0;
        }else{
            cnt++;
        }
    }
    //cout << N << endl;
    //cout << cnt << endl;
    if(cnt > 0){
        map<ll,ll> tm;
        if(st==0){
            for(auto&e:LX){
                tm[e.fi+cnt] = 1;
                if(init)continue;
                tm[e.fi-cnt] = 1;
            }
            LX = tm;
            h.push_back(cnt);
        }else{
            for(auto&e:LY){
                tm[e.fi+cnt] = 1;
                tm[e.fi-cnt] = 1;
            }
            LY = tm;
            v.push_back(cnt);
        }
    }
    if(LX[x]&&LY[y]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}