#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (A > B) swap(A, B);
    cout << (A < C && C < B ? "Yes\n" : "No\n");
    return 0;
}
