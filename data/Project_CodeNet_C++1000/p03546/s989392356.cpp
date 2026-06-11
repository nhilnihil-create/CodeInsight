#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

int H, W;
int cost[10][10];

signed main(){
    cin >> H >> W;

    rep(i, 10){
        rep(j, 10){
            cin >> cost[i][j];
        }
    }

    rep(i, 10){
        rep(j, 10){
            rep(k, 10){
                cost[j][k] = min(cost[j][k], cost[j][i]+cost[i][k]);
            }
        }
    }

    int ans = 0;
    rep(i, H){
        rep(j, W){
            int A;
            cin >> A;
            if(A == -1) continue;
            ans += cost[A][1];
        }
    }
    cout << ans << endl;
}