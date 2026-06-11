#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <math.h> // sqrt
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <iomanip> // setprecision
#include <bitset> // bitset
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using pii = pair<int, int>;
using psi = pair<string, int>;

int main() {
    int N;
    cin >> N;
    vi vx(N), vy(N), vh(N);
    int si = -1;
    for (int i = 0; i < N; i++) {
        cin >> vx[i] >> vy[i] >> vh[i];
        if (vh[i] > 0) {
            si = i;
        }
    }
    for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
            int h = vh[si] + abs(x - vx[si]) + abs(y - vy[si]);
            bool check = true;
            for (int i = 0; i < N; i++) {
                if (vh[i] > 0 && h - vh[i] != abs(x - vx[i]) + abs(y - vy[i])) {
                    check = false;
                    break;
                }
                if (vh[i] == 0 && h > abs(x - vx[i]) + abs(y - vy[i])) {
                    check = false;
                    break;
                }
            }
            if (check) {
                cout << x << " " << y << " " << h << endl;
                return 0;
            }
        }
    }
}
