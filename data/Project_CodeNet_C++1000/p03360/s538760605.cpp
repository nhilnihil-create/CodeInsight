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
    //int a, b, c; cin >> a >> b >> c;
    vector<int> hairetu(3);
    rep(i, 3) cin >> hairetu[i];
    int k; cin >> k;

    rep(i,k){
        sort(all(hairetu));
        hairetu[2] *= 2;
    }
    int result = 0;
    rep(i,3) result += hairetu[i];

    cout << result << endl;

    return 0;
}
