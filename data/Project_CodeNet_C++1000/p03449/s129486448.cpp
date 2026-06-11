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
    vector<vector<int>> a(2,vector<int> (n));
    rep(i,2){
        rep(j,n){
            cin >> a[i][j];
        }
    }
    int res = 0;
    int ans = 0;
    int tmp = 0;
    rep(i,n){
        rep(j,n){
            if(j == i) {
                ans += a[tmp][j];
                tmp += 1;
            }
            ans += a[tmp][j];
        }
        res = max(res,ans);
        ans = 0;
        tmp = 0;
    }
    cout << res << endl;



    cout << endl;
    return 0;
}
