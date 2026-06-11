#include <iostream>
#include <vector>
using namespace std;
#define vi vector<int>
#define vvi vector<vector <int>>
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int h, w;
    cin >> h >> w;
    vvi a(h, vi(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    vvi ans;
    vi dx{1, 0};
    vi dy{0, 1};
    bool flag;
    rep(i, h){
        rep(j, w){
            if(a[i][j] % 2 == 1){
                flag = true;
                rep(k, 2){
                    int ny, nx;
                    ny = i + dy[k];
                    nx = j + dx[k];
                    if(0 <= ny && ny < h && 0 <= nx && nx < w){
                        if(a[ny][nx] % 2 == 1){
                            a[ny][nx] += 1;
                            a[i][j] -= 1;
                            ans.emplace_back(vi {i+1, j+1, ny+1, nx+1});
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag){
                    if(j + 1 < w){
                        a[i][j+1] += 1;
                        a[i][j] -= 1;
                        ans.emplace_back(vi {i+1, j+1, i+1, j+2});
                    }
                    else if(i + 1 < h){
                        a[i+1][j] += 1;
                        a[i][j] -= 1;
                        ans.emplace_back(vi {i+1, j+1, i+2, j+1});
                    }
                }
            }
        }
    }
    
    int n;
    n = ans.size();
    cout << n << endl;
    rep(i, n){
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
    }
}
