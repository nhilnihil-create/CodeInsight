#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const ll LLINF = 1LL<<60;
/* -- template -- */
int N, A, B, C;
int l[8];
int dfs(int a, int b, int c, int i){
    int minv = INF;
    if(i == N)return ((a == 0 || b == 0 || c == 0) ? INF : abs(a - A) + abs(b - B) + abs(c - C) - 30);
    minv = min(minv, dfs(a + l[i], b, c, i + 1) + 10);
    minv = min(minv, dfs(a, b + l[i], c, i + 1) + 10);
    minv = min(minv, dfs(a, b, c + l[i], i + 1) + 10);
    minv = min(minv, dfs(a, b, c, i + 1));
    return minv;
}

int main(){
    cin >> N >> A >> B >> C;
    rep(i, N)cin >> l[i];
    cout << dfs(0, 0, 0, 0) << endl;
}
