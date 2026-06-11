#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    ll n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    rep(i,n) cin >> x[i];
  	y = x;
    sort(x.begin(),x.end());
    int a = x[n/2 - 1];
    int b = x[n/2];
    rep(i,n){
        if(y[i] <= a) cout << b << endl;
        else cout << a << endl;
    }
}