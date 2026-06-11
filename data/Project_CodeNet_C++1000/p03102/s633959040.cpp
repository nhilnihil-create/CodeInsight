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
#include <math.h> // sqrt
using namespace std;

int main() {
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> data(M);
    for (int i = 0; i < M; i++) {
        cin >> data.at(i);
    }
    vector<vector<int>> sor(N,vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> sor.at(i).at(j);
        }
    }
    int ans = 0;
    int sum;
    for (int i = 0; i < N; i++) {
        sum = 0;
        for (int j = 0; j < M; j++) {
            sum += data.at(j) * sor.at(i).at(j);
        }
        sum += C;
        if (0 < sum) {
            ans++;
        }
    }
    cout << ans << endl;
}