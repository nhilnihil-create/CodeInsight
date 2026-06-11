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
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using pii = pair<int, int>;
using psi = pair<string, int>;

int main() {
    int N, M;
    cin >> N >> M;
    vb ans(M, true);
    for (int j = 0; j < N; j++) {
        int K;
        cin >> K;
        vi data(K);
        for (int i = 0; i < K; i++) {
            cin >> data.at(i);
        }
        for (int i = 0; i < M; i++) {
            if (!ans.at(i)) {
                continue;
            }
            bool finished = false;
            for (int k = 0; k < K; k++) {
                if (i == data.at(k) - 1) {
                    finished = true;
                    break;
                }
            }
            if (!finished) {
                ans.at(i) = false;
            }
        }
    }
    int count = 0;
    for (bool b : ans) {
        if (b) {
            count++;
        }
    }
    cout << count << endl;
}