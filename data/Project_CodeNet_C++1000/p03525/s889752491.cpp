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
    vector<ll> D(N);
    vector<ll> v(13),u(24);
    rep(i,N){
        cin >> D[i];
        v[D[i]]++;
    }
    if(v[0]){
        cout << 0 << endl;
        return 0;
    }
    v[0]++;
    u[0]++;
    bool flag = true;
    REP(i,1,13){
        if(v[i] >= 3){
            cout << 0 << endl;
            return 0;
        }
        if(v[i] == 2){
            u[i]++;
            u[(24-i)]++;
        }else if(v[i] == 1){
            if(flag){
                u[i]++;
            }else{
                u[24-i]++;
            }
            flag = !flag;
        }
    }
    ll m = 1e18;
    ll cnt = 1;
    REP(i,1,24){
        if(u[i] == 0){
            cnt++;
        }else{
            cmin(m,cnt);
            cnt = 1;
        } 
    }
    cmin(m,cnt);
    cout << m << endl;
}