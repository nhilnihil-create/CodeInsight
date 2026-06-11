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
    int N;
    cin >> N;

    if (N == 1) {
        cout << "Hello World" << endl;
    } else {
        int A, B;
        cin >> A >> B;
        cout << A+B << endl;
    }
   return 0;
}