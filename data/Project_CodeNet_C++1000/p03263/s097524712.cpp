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

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> a(H,vector<int>(W));
    vector<vector<int>> ans;
    rep(i,H)rep(j,W) cin >> a[i][j];
    rep(i,H){
        rep(j,W-1){
            if(a[i][j] % 2 == 0) continue;
            a[i][j+1]++;
            vector<int> res(4);
            res[0] = i+1;
            res[1] = j+1;
            res[2] = i+1;
            res[3] = j+2;
            ans.push_back(res);
        }
    }
    rep(i,H-1){
        if(a[i][W-1] % 2 == 0) continue;
        a[i+1][W-1]++;
        vector<int> res(4);
        res[0] = i+1;
        res[1] = W;
        res[2] = i+2;
        res[3] = W;
        ans.push_back(res);
    }
    cout << ans.size() << endl;
    for(auto v:ans){
        rep(i,4){
            if(i == 3) cout << v[i] << endl;
            else cout << v[i] << ' ';
        }
    }
}