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
const int d5 = 100100;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    int res = 0;
    for (int i = 1;i<=n;i++){
        if(i<=k)
            continue;
        int t=(i - k) * (n / i);
        res += t;
        int x = n - (n/i)*i;
        if (x >= k)
            res += x - k+1*(k!=0);
    }
    cout << res << endl;
}