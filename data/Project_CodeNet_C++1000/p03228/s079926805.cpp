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
    int A, B, K;
    cin >> A >> B >> K;
    int t = 0;
    rep(i, K) {
        if (t == 0) {
            if (A % 2) --A;
            B += A / 2;
            A = A / 2;
            t = 1;
        } else {
            if (B % 2) --B;
            A += B / 2;
            B = B / 2;
            t = 0;
        }
    }
    cout << A << " " << B << "\n";
    return 0;
}
