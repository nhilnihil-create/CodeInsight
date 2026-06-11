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
    int a; cin >> a;
    int b; cin >> b;
    int c; cin >> c;
    int x; cin >> x;

    int cnt = 0;
    repr(i, 0, a+1){
        repr(j, 0, b+1){
            repr(k, 0, c+1){
                if(500*i + 100*j + 50*k == x) cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
