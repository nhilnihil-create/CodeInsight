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
    string S;
    cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    map<ll,ll> mp1,mp2;
    rep(i,N){
        mp1[A[i]]++;
        i++;
    }
    rep(i,N){
        i++;
        mp2[A[i]]++;
    }
    ll m1 = 0, m2 = 0;
    vector<Pll> v1,v2;
    for(auto& e:mp1){
        v1.push_back(Pll(e.second, e.first));
    }
    for(auto& e:mp2){
        v2.push_back(Pll(e.second, e.first));
    }
    sort(v1.begin(), v1.end(), greater<Pll>());
    sort(v2.begin(), v2.end(), greater<Pll>());
    ll dec = 0;
    if(v1[0].second != v2[0].second){
        dec = v1[0].first + v2[0].first;
    }else{
        if(N >= 4){
            dec = max(v1[0].first + v2[1].first, v1[1].first + v2[0].first);
        }else{
            dec = 1;
        }
    }

    cout << N - dec << endl;
}