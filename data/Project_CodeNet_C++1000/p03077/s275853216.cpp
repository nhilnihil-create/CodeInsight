#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const ll INF = +10010010000;

typedef pair<ll,ll> P;
const ll MO = 1000000007;

int main(){
    ll n;
    cin >> n;
    vector<ll> c(5);
    rep(i,5)cin>>c[i];
    ll mini = c[0];
    rep(i,5){
        mini = min(mini,c[i]);
    }
    cout << 4+(n+(mini-1))/mini << endl;
    return 0;

}