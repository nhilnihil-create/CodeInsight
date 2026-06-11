#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n,m,X,Y;
    cin >> n >> m >> X >> Y;
    vector<int> x(n),y(m);
    rep(i,n) cin >> x[i];
    rep(i,m) cin >> y[i];
    sort(all(x));
    sort(all(y));
    if(x[n-1] < y[0] && x[n-1] < Y && y[0] > X) cout << "No War" << endl;
    else cout << "War" << endl;
}