#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <math.h>
#include <map>
#include <stack>
using namespace std;
static const int INF = 1e9+7;
// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, a, b) for (int i =a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define PI 3.14159265359

int main(){

    int n, m; cin >> n >> m;
    int kind[50] = {};

    rep(i,n){
        int k; cin >> k;
        rep(i, k){
            int tmp; cin >> tmp;
            kind[tmp]++;
        }
    }

    int ans = 0;
    rep(i,m+1){
        if(kind[i] == n) ans++;
    }

    cout << ans << endl;

    return 0;
}
