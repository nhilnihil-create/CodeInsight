#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000
#define MAX 200001
#define PI 3.141592653589793

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> A(h);
    queue<pair<int, int>> q;
    vector<vector<ll>> d(h,vector<ll>(w,INF));
    rep(i,h) cin >> A[i];
    rep(i,h)rep(j,w){
        if(A[i][j] == '#'){
            q.push({i,j});
            d[i][j] = 0;
        }
    }
    while(!q.empty()){
        int now_y = q.front().first;
        int now_x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int new_y = now_y + dy[i];
            int new_x = now_x + dx[i];
            if(new_y < 0 || h <= new_y || new_x < 0 || w <= new_x) continue;
            if(A[new_y][new_x] == '#') continue;
            else if(d[new_y][new_x] > d[now_y][now_x] + 1){
                d[new_y][new_x] = d[now_y][now_x] + 1;
                q.push({new_y,new_x});
            }
        }
    }
    ll ans = 0;
    rep(i,h)rep(j,w){
        ans = max(ans, d[i][j]);
    }
    cout << ans << endl;
} 