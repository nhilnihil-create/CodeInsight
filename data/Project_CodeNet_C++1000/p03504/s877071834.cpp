#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <functional>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()
int dy[8] = {-1,0,1,0,-1,1,1,-1};
int dx[8] = {0,1,0,-1,1,1,-1,-1};
const int mod = 1000000007;
const int inf = mod*mod;
const int d5 = 100010;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,C;
    cin >> n >> C;
    int s[d5], t[d5], c[d5];
    int ss[2 * d5], tt[2 * d5];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> t[i] >> c[i];
    }
    for (int i = 1; i <= C;i++){
        fill(tt, tt + 2*d5, 0);
        for (int j = 0; j < n;j++){
            if(c[j]==i){
                tt[s[j] * 2 - 1]++;
                tt[t[j] * 2]--;
            }
        }
        for (int j = 1; j < 2 * d5;j++){
            tt[j] += tt[j - 1];
        }
        for (int j = 0; j < 2 * d5;j++){
            if(tt[j]>0){
                ss[j]++;
            }
        }
    }
    int res = -1;
    for (int j = 0; j < 2 * d5-10;j++)
        res = max(res, ss[j]);
    cout << res << endl;
}