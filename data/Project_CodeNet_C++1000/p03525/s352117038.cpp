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

int main() {
    int N; cin >> N;
    vector<int> vec(13); // [0,13)
    vec[0]++;
    for (int i = 0; i < N; i++) {
        int d; cin >> d;
        vec[d]++;
    }
    int ans = -1;
    bool fg = false;
    for (int i = 0; i < 13; i++) {
        if (vec[i] > 2 || vec[0] > 1) {
            fg = true;
        }
    }

    if (fg) {
        ans = 0;
        cout << ans << endl;
    }
    else {
        vector<int> const_arr;
        for (int i = 0; i < 13; i++) {
            if (vec[i] == 2) {
                const_arr.push_back(i);
                const_arr.push_back(24 - i);
            }
        }
        vector<int> dynamic_arr;
        for (int i = 0; i < 13; i++) {
            if (vec[i] == 1) {
                dynamic_arr.push_back(i);
            }
        }
        int M = dynamic_arr.size();
        vector<int> tmp;
        for (int p = 0; p < (1 << M); p++) {
            bitset<40> bs = p;
            tmp = dynamic_arr;
            for (int i = 0; i < M; i++) {
                if (bs[i] == true) {
                    tmp[i] = 24 - tmp[i];
                    tmp[i] %= 24;
                }
            }
            tmp.insert(tmp.end(), const_arr.begin(), const_arr.end());
            sort(ALL(tmp));
            int diff = 1000;
            for (int pos = 1; pos < tmp.size(); pos++) {
                diff = min(diff, tmp[pos] - tmp[pos - 1]);
            }
            int findif = min(abs(tmp.back() - tmp.front()), 24 - abs(tmp.back() - tmp.front()));
            diff = min(diff, findif);

            ans = max(ans, diff);
        }
        cout << ans << endl;
    }
}