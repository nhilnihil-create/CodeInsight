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
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    ll prev = -1;
    ll ans = 0;
    rep(i,N){
        if(A[i] == prev + 1){
            prev++;
            if(i!=0){
                ans++;
            }
        }else if(A[i] > prev + 1){
            cout << -1 << endl;
            return 0;
        }else{
            prev = A[i];
            if(A[i] != 0){
                ans += A[i];
            }
        }
    }
    cout << ans << endl;
}