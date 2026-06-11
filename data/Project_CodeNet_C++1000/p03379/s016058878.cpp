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

bool bysecond(const vi & lhs, const vi & rhs) {
    if (lhs[1] != rhs[1]) {
        return lhs[1] < rhs[1];
    }
    else {
    }
}
int main() {
    int N; cin >> N;
    vvi vec(N, vi(3));
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        x;
        vec[i] = { x,i,-1 };
    }
    sort(ALL(vec)); // sort by values x
    for (int i = 0; i < N; i++) {
        vec[i][2] = i;
    }
    int first_half = vec[N / 2 - 1][0];
    int second_half = vec[N / 2][0];
    sort(ALL(vec), bysecond);
    for (int i = 0; i < N; i++) {
        if (vec[i][2] < N / 2) {
            cout << second_half << endl;
        }
        else {
            cout << first_half << endl;
        }
    }
}