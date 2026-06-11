#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;

const int mod = 1000000007;
const int inf = 1e9;
#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>> grid(h, vector<int>(w));
    for(int i = 0; i < h; i++)for(int j = 0; j < w; j++) cin >> grid[i][j];
    vector<pair<P, P>> ans;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(i == h-1 && j == w-1) break;
            if(grid[i][j]&1^1) continue;

            if(j == w-1) {
                grid[i+1][j]++;
                P a = P(i, j);
                P b = P(i+1, j);
                ans.push_back(pair<P, P>(a, b));
            }else{
                grid[i][j+1]++;
                P a = P(i, j);
                P b = P(i, j+1);
                ans.push_back(pair<P, P>(a, b));
            }
        }
    }
    cout << ans.size() << endl;
    for(auto p : ans) {
        cout << p.first.first+1 << " " << p.first.second+1 << " " << p.second.first+1 << " " << p.second.second+1 << endl;
    }
}