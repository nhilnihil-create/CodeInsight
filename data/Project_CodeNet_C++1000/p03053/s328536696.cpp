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

vector<int> operator+(const vi& v1, const vi& v2) {
    return { v1[0] + v2[0],v1[1] + v2[1] };
}

vector<vector<int>> moves = { {1, 0}, { -1, 0 }, { 0,1 }, { 0,-1 } };

bool isWithin(const vector<int>& coordinate, int& H, int& W) {
    int y = coordinate[0];
    int x = coordinate[1];
    if (-1 < y && y < H) {
        if (-1 < x && x < W) {
            return true;
        }
    }
    return false;
}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

vector<vector<int>> bfs(vector<vector<char>> table) {
    int H = table.size(); int W = table[0].size();
    vector<vector<int>> dp(table.size(), vi(table[0].size(), pint_INF));
    queue<vi> search_ij;
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[0].size(); j++) {
            if (table[i][j] == '#') {
                dp[i][j] = 0;
                search_ij.push({ i,j });
            }
        }
    }
    while (!search_ij.empty()) {
        vi coor = search_ij.front(); search_ij.pop();
        for (auto move : moves) {
            vi next = coor + move;
            if (isWithin(next, H, W)) {
                if (chmin(dp[next[0]][next[1]], dp[coor[0]][coor[1]] + 1)) {
                    search_ij.push(next);
                }
            }
        }
    }
    return dp;
}

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> vec(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> vec[i][j];
    vvi dist_table = bfs(vec);

    int M = -1;
    for (auto row : dist_table) {
        for (auto elem : row) {
            M = max(M, elem);
        }
    }
    cout << M << endl;
    sysp;
}