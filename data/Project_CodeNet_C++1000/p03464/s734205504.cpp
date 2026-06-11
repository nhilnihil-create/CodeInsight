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
    ll K;
    cin >> K;
    vector<ll> A(K);
    rep(i,K){
        cin >> A[i];
    }
    if(A[K-1] != 2){
        cout << -1 << endl;
        return 0;
    }
    //ll cur = 2;
    ll M = 2;
    ll m = 2;
    ll MM;
    ll mm;
    rep(i,K){
        if(m % A[K-1-i] == 0){
            mm = m/A[K-1-i];
        }else{
            mm = m/A[K-1-i];
            mm++;
        }
        MM = M/A[K-1-i];

        //M = M/A[K-1-i];
        /*if(M < 1){
            cout << -1 << endl;
            return 0;
        }*/
        /*if(m > M){
            m = M;
        }*/
        mm = A[K-1-i] * mm;
        MM = A[K-1-i] * MM + A[K-1-i] - 1;
        if(MM < m || mm > M){
            cout << -1 << endl;
            return 0;
        }
        M = MM;
        m = mm;
        //cout << m << " a " << M << endl;
        //cur = A[K-2-i];
        //M = M*2-1;
        //m = max(m, A[K-2-i]);
    }
    cout << m << " " << M << endl;
}