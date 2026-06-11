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

int f(vector<pair<int, vi>> &data, vi &p, vb &bit, int n) {
    if (n == 0) {
        int M = p.size();
        for (int i = 0; i < M; i++) {
            int on = 0;
            for (int j = 0; j < data[i].first; j++) {
                if (bit[data[i].second[j] - 1]) {
                    on++;
                    on %= 2;
                }
            }
            if (on != p[i]) {
                return 0;
            }
        }
        return 1;
    }
    int N = bit.size();
    bit[N - n] = true;
    int anst = f(data, p, bit, n - 1);
    bit[N - n] = false;
    int ansf = f(data, p, bit, n - 1);
    return anst + ansf;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, vi>> data(M);
    for (int i = 0; i < M; i++) {
        pair<int, vi> p;
        int k;
        cin >> k;
        vi s(k);
        for (int j = 0; j < k; j++) {
            cin >> s[j];
        }
        p = make_pair(k, s);
        data[i] = p;
    }
    vi p(M);
    for (int i = 0; i < M; i++) {
        cin >> p[i];
    }
    vb bit(N, true);
    int ans = f(data, p, bit, N);
    cout << ans << endl;
}