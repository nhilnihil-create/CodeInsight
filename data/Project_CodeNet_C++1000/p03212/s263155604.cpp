#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <list>
#include <functional>
#include <numeric>
#include <stack>
#include <tuple>

using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
const int INF = 100000000;
const long long LINF = 1000000000000000000;
const long long MOD = 998244353;
const double EPS = 1e-6;
using pii = std::pair<int, int>;
using ll = long long;
using pLL = std::pair<ll, ll>;
#define SORT(v) std::sort(v.begin(), v.end())
#define RSORT(v) std::sort(v.rbegin(), v.rend())
constexpr auto PI = 3.14159265358979323846264338327950L;
long long N;
void dfs(long long cur,int use,long long &counter) {
    // 数列の長さが N に達したら打ち切り
    if (cur > N) {
        // 処理
        return;
    }
    if(use == 0b111)++counter;

    dfs(cur * 10 + 7 , use | 0b001,counter);
    dfs(cur * 10 + 5 , use | 0b010,counter);
    dfs(cur * 10 + 3 , use | 0b100,counter);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N;
    long long res=0;
    dfs(0,0,res);
    cout << res <<endl;
    return 0;
}
