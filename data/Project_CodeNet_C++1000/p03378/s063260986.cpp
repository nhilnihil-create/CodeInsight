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
    int n, m, x; cin >> n >> m >> x;
    int board[101] = {};
    rep(i, m){
        int tmp; cin >> tmp;
        board[tmp] = 1;
    }

    int first = 0;
    rep(i, x+1){
        if(board[i] == 1) first++;
    }
    int second = 0;
    repr(i, x+1, n+1){
        if(board[i] == 1) second++;
    }
    cout << min(first, second) << endl;

    return 0;
}
