#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<int> > vec(10, vector<int>(10));
    rep(i,10){
        rep(j,10){
            cin >> vec[i][j];
        }
    }
    rep(k,10){
        rep(i,10){
            rep(j,10){
                vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);
            }
        }
    }
    vector<vector<int> > wall(H, vector<int> (W));
    rep(i,H){
        rep(j,W){
            cin >> wall[i][j];
        }
    }
    int ans = 0;
    rep(i,H){
        rep(j,W){
            if (wall[i][j] != -1){
                ans += vec[wall[i][j]][1];
            }
        }
    }
    cout << ans << endl;    
}

