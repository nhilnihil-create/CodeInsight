#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h){
        rep(j, w){
            cin >> a[i][j];
        }
    }
    int n = 0;
    vector<vector<ll>> ans;
    rep(i, h){
        rep(j, w){
            if(a[i][j]%2 == 0) continue;
            else{
                if(i>0&&a[i-1][j]%2 == 1){
                    a[i][j]--;a[i-1][j]++;
                    n++;
                    ans.push_back({i+1, j+1, i, j+1});
                    continue;
                }
                if(j>0&&a[i][j-1]%2 == 1){
                    a[i][j]--; a[i][j-1]++;
                    n++;
                    ans.push_back({i+1, j+1, i+1, j});
                    continue;
                }
                if(i<h-1&&a[i+1][j]%2==1){
                    a[i][j]--;a[i+1][j]++;
                    n++;
                    ans.push_back({i+1, j+1, i+2, j+1});
                    continue;
                }
                if(j<w-1&&a[i][j+1%2==1]){
                    a[i][j]--;a[i][j+1]++;
                    n++;
                    ans.push_back({i+1, j+1, i+1, j+2});
                    continue;
                }
                if(i<h-1){
                    a[i][j]--;a[i+1][j]++;
                    n++;
                    ans.push_back({i+1, j+1, i+2, j+1});
                    continue;
                }
                if(j<w-1){
                    a[i][j]--;a[i][j+1]++;
                    n++;
                    ans.push_back({i+1, j+1, i+1, j+2});
                    continue;
                }
            }
        }
    }
    cout << n << endl;
    rep(i,n){
        rep(j, 3){
            cout << ans[i][j] << " ";
        }
        cout << ans[i][3] << endl;
    }
    return 0;
}