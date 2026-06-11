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
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using pii = pair<int, int>;
using psi = pair<string, int>;

int main() {
    string S, T;
    cin >> S >> T;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        bool check = true;
        int j = i;
        for (int k = 0; k < N; k++) {
            if (j == N) {
                j = 0;
            }
            if (S[j] != T[k]) {
                check = false;
                break;
            }
            j++;
        }
        if (check) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
