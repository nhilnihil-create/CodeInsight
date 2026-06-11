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
    ll N;
    cin >> N;
    ll ng = 1;
    bool flag = false;
    rep(i,100010){
        if(ng*(ng-1) == 2*N){
            flag = true;
            break;
        }
        ng++;
    }
    if(!flag){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << ng << endl;
    ll ne = ng-1;
    vector<vector<ll>> v(ne);
    ll num = 1;
    rep(i,ne){
        rep(j,i+1){
            v[i].push_back(num);
            num++;
        }
    }
    rep(i,ng-1){
        cout << ne;
        ll yoko = i+1;
        ll tate = ne - yoko + 1;
        ll t = i;
        ll u = 0;
        rep(j,ne){
            cout << " " << v[t][u];
            if(u == yoko-1){
                t++;
            }else{
                u++;
            }
        }
        cout << endl;
    }
    cout << ne;
    rep(i,ne){
        cout << " " << v[i].back();
    }
    cout << endl;
}