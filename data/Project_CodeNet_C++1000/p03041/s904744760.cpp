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
    int N, K;
    string S;
    cin >> N >> K >> S;
    K--;
    if (S.at(K) == 'A') {
        S.at(K) = 'a';
    }
    else if (S.at(K) == 'B') {
        S.at(K) = 'b';
    }
    else {
        S.at(K) = 'c';
    }
    cout << S << endl;
}