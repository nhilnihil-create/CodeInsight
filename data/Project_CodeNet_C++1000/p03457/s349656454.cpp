#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> t(n+1);
    vector<int> x(n+1);
    vector<int> y(n+1);
    rep(i,n){
        cin >> t[i+1] >> x[i+1] >> y[i+1];
    }
    x[0] = y[0] = t[0] = 0;
    int dx,dy,dt;
    rep(i,n){
        dx = abs(x[i+1] - x[i]);
        dy = abs(y[i+1] - y[i]);
        dt = abs(t[i+1] - t[i]);
        if((dx+dy) % 2 != dt%2) {
            cout << "No" << endl;
            return 0;
        }
        if(dt < dx+dy) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;


    cout << endl;
    return 0;
}
