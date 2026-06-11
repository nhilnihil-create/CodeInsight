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
    int n, x; cin >> n >> x;
    vector<int> m(n);
    int total = 0;
    rep(i, n){
        cin >> m[i];
        total += m[i];
    }

    sort(all(m));
    x -= total;

    cout << x / m[0] + n << endl;

    return 0;
}
