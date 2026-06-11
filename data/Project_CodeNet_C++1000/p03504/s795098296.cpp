#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 100000000000
#define MAX 200001
#define MOD 1000000007
ll fac[MAX], finv[MAX], inv[MAX];
const int MX = 1000005;

int main(){
    int N, C;
    int ans = 0;
    cin >> N >> C;
    vector<vector<int>> time(30, vector<int>(100010,0));
    vector<vector<pair<int, int>>> v(30);
    for(int i = 0; i < N; i++){
        int s, t, c;
        cin >> s >> t >> c;
        c--;
        v[c].push_back({s, t});
    }
    for(int i = 0; i < 30; i++){
        sort(v[i].begin(), v[i].end());
    }
    for(int i = 0; i< 30; i++){
        int n = v[i].size();
        for(int j = 0; j < n; j++){
            if(time[i][v[i][j].first + 1] == -1){
                time[i][v[i][j].first + 1] = 0;
            }
            else{
                time[i][v[i][j].first] += 1;
            }
            time[i][v[i][j].second + 1] -= 1;
        }
    }
    vector<int> res(100010, 0);
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 100010; j++){
            res[j] += time[i][j];
        }
    }
    for(int i = 1; i < 100010; i++){
        res[i] += res[i-1];
        ans = max(ans, res[i]);
    }
    cout << ans << endl;
}