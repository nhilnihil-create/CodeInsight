#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N), S(N+1);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        S[i+1] = S[i] + A[i];
    }
    map<ll,ll> mp;
    rep(i,N){
        mp[S[i+1]]++;
    }
    ll sum = 0;
    for(auto& e:mp){
        sum += e.second*(e.second-1)/2;
    }
    sum += mp[0];
    cout << sum << endl; 
}
