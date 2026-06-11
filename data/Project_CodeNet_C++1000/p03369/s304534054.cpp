#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
ll const INF = 1LL << 60;

int main() {
    string N;
    cin >> N;

    int ans = 700;
    
    for (int i = 0; i < 3; i++) {
        if (N[i] == 'o')
            ans += 100;
    }

    cout << ans << endl;
    return 0;
}