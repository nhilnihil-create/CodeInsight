#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, m, X, Y; cin >> n >> m >> X >> Y;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    x.push_back(X);
    sort(RALL(x));
    vector<int> y(m);
    rep(i,m) cin >> y[i];
    y.push_back(Y);
    sort(ALL(y));
    if(x[0]+1 <= y[0]) cout << "No War" << endl;
    else cout << "War" << endl;
}