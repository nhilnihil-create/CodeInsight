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
#include <cmath>
#include <limits>
#include <list>
#include <cassert>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pNO cout << "NO" << endl
#define pYES cout << "YES" << endl
#define endl "\n"
#define pi 3.14159265358979
using namespace std;
using ll = long long;

template<typename T>
vector<vector<T>> accum2d(vector<vector<T>> & vec) { // 0-indexed
    int H = vec.size();
    int W = vec[0].size();
    vector<vector<T>> res(H + 1, vector<T>(W + 1));
    for (int i = 1; i < H + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            res[i][j] = vec[i - 1][j - 1] - res[i - 1][j - 1] + res[i][j - 1] + res[i - 1][j];
        }
    }
    return res;
}

template<typename T>
T sum_square(vector<vector<T>> & accum, vector<T> coor0, vector<T> coor1) { // 0-indexed
    T res = accum[coor1[0] + 1][coor1[1] + 1] + accum[coor0[0]][coor0[1]] - accum[coor1[0] + 1][coor0[1]] - accum[coor0[0]][coor1[1] + 1];
    return res;
}

int main() {
    int N, M, Q; cin >> N >> M >> Q;
    vector<vector<int>> vec(N, vi(N));
    for (int i = 0; i < M; i++) {
        int l, r; cin >> l >> r;
        --l; --r;
        vec[l][r]++;
    }

    vector<vector<int>> acc = accum2d(vec);

    for (int qq = 0; qq < Q; qq++) {
        int p, q; cin >> p >> q; --p; --q;
        cout << sum_square(acc, { p,p }, { q,q }) << endl;;
    }

}