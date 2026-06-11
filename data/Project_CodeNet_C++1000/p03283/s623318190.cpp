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
    ll N,M,Q;
    cin >> N >> M >> Q;
    vector<vector<ll>> A(N+1,vector<ll>(N+1)), S(N+1,vector<ll>(N+1));
    ll L,R;
    rep(i,M){
        cin >> L >> R;
        L--;R--;
        A[L][R]++;
        //PR(A,N+1);
    }
    ll p, q;
    //PR(A,N+1);
    rep(i,N){
        rep(j,N){
            S[i+1][j+1] = S[i+1][j] + A[i][j];
        }
    }
    //PR(A,N+1);
    vector<ll> ans;
    rep(i,Q){
        cin >> p >> q;
        ll sum = 0;
        REP(j,p,q+1){
            sum += S[j][q] - S[j][p-1];
            //cmin(m,A[j]);
        }
        cout << sum <<endl;
        //ans.push_back(sum);
    }
    //PR(ans,Q);
    //cout << "aaaaa" << endl;
}