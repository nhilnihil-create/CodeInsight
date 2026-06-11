#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int h,w; cin >> h >> w;
    vector<vector<int>> a(h,vector<int>(w));
    rep(i,h){
        rep(j,w) cin >> a[i][j];
    }
    vector<vector<int>> ans;
    rep(i,h-1){
        rep(j,w){
            if(a[i][j] %2 == 1){
                ans.push_back({i,j,i+1,j});
                a[i+1][j]++;
            }
        }
    }
    rep(i,w-1){
        if(a[h-1][i] %2 == 1){
            ans.push_back({h-1,i,h-1,i+1});
            a[h-1][i+1]++;
        }
    }
    int n = ans.size();
    cout << n << endl;
    rep(i,n){
        cout << ans[i][0]+1 << " " << ans[i][1]+1 << " " << ans[i][2]+1 << " " <<  ans[i][3]+1 << endl;
    }
}