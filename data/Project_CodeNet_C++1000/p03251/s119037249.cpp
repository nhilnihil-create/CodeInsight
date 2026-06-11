#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<int> xx(n+1); rep(i,n) cin >> xx[i];
    vector<int> yy(m+1); rep(i,m) cin >> yy[i];
    xx[n] = x; yy[m] = y;

    sort(all(xx));
    sort(all(yy));

    if(xx[n] < yy[0]) cout << "No War" << endl;
    else cout << "War" << endl;
}
