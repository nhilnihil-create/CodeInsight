#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
using namespace std;


int main() {
    string S;
    cin >> S;
    int O = 0;
    int A = 0;

    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) == '1') {
            O++;
        }
        else {
            A++;
        }
    }
    int N = min(O, A);
    cout << N * 2 << endl;
}
