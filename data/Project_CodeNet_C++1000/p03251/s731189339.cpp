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
#include <iomanip>
#include <ctype.h>

using namespace std;
using ll = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

#define rep(i,N) for(int i=0;i<(int)N;++i)

ll GCD(ll x, ll y) {
    if (y == 0) return x;
    else return GCD(y, x % y);
}

bool my_compare(pair<string, int> a, pair<string, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }

    if (a.second != b.second) {
        return a.second > b.second;
    }
    else {
        return true;
    }
}

int main()
{
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;

    vector<int> x(N);
    vector<int> y(M);

    rep(i, N) cin >> x[i];
    rep(i, M) cin >> y[i];

    int a = -100;
    int b = 100;

    rep(i, N) if (x[i] > a) { a = x[i]; }
    rep(i, M) if (y[i] < b) { b = y[i]; }

    if(a<X || b-a<0 || b>=Y) { cout << "War" << endl; goto xyz; }

    rep(i, N) {
        if (x[i] >= b) { cout << "War" << endl; goto xyz; }
    }

    cout << "No War" <<endl;

xyz:;
}