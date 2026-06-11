#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep01(i, n) for(int i = 0; i < (n) + 1; i++)
#define rep10(i, n) for(int i = 1; i < (n); i++)
#define rep11(i, n) for(int i = 1; i < (n) + 1; i++)
#define all(a) (a).begin(), (a).end()
typedef long long int ll;
typedef struct { int x; int y; } Pos;
using namespace std;

int N, M;
vector<pair<int, int>> a;
vector<int> b;
int main() {
    cin >> N >> M;
    a = vector<pair<int, int>> (M);
    rep(i, M) cin >> a[i].first >> a[i].second;
    // 終点で小さい順ソート
    sort(all(a), [](auto x, auto y) -> bool { return x.second < y.second; });
    //まず一番小さい終点の橋を壊す
    b.push_back(a[0].second-1);
    rep10(i, M) {
        bool ok = false;
        //i番目の要望が達成できているかチェック
        rep(j, (int)b.size()) {
            if (b[j] >= a[i].first && b[j] < a[i].second) ok = true;
        }
        //達成できていない場合、終点の橋を壊す
        if (!ok) b.push_back(a[i].second-1);
    }
    cout << b.size() << endl;
    return 0;
}