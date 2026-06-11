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
    string S;
    cin >> S;
    if (S[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }
    int c = 0;
    int N = S.size();
    for (int i = 2; i < N - 1; i++) {
        if (S[i] == 'C') {
            c++;
        }
    }
    if (c != 1) {
        cout << "WA" << endl;
        return 0;
    }
    for (int i = 2; i < N - 1; i++) {
        if (isupper(S[i]) && S[i] != 'C') {
            cout << "WA" << endl;
            return 0;
        }
    }
    if (isupper(S[1]) || isupper(S[N - 1])) {
        cout << "WA" << endl;
        return 0;
    }
    cout << "AC" << endl;
}
