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
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using pii = pair<int, int>;
using psi = pair<string, int>;

int main() {
    int N;
    cin >> N;
    bool YYMM = false;
    bool MMYY = false;
    if (N % 100 < 13 && N % 100 != 0) {
        YYMM = true;
    }
    N = floor(N / 100);
    if (N < 13 && N != 0) {
        MMYY = true;
    }
    if (YYMM && MMYY) {
        cout << "AMBIGUOUS" << endl;
        return 0;
    }
    if (YYMM) {
        cout << "YYMM" << endl;
        return 0;
    }
    if (MMYY) {
        cout << "MMYY" << endl;
        return 0;
    }
    cout << "NA" << endl;
}