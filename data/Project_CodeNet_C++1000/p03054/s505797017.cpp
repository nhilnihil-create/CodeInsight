#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
#include <limits>
#include <algorithm>

#define MOD_BIG 1000000007
#define MOD_BIG2 998244353
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using ll = long long;
using std::vector;

template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) {
    vec.resize(len);
    for (auto &v : vec) ndarray(v, args...);
}

//////////////////////////////////////



//////////////////////////////////////

int main() {
    
    ll H, W, N;
    ll sr, sc;
    cin >> H >> W >> N;
    cin >> sr >> sc;
    string S, T;
    cin >> S;
    cin >> T;
    
    vector<ll> m(4);
    m[0] = sr;
    m[1] = W - sc + 1;
    m[2] = H - sr + 1;
    m[3] = sc;
    vector<ll> b(4), w(4);
    bool out = false;
    for (ll i = 0; i < N; i++) {
        if (S[i] == 'U') b[0] += 1;
        if (S[i] == 'R') b[1] += 1;
        if (S[i] == 'D') b[2] += 1;
        if (S[i] == 'L') b[3] += 1;
        
        for (int j = 0; j < 4; j++) {
            if (1 > w[j] + m[j] - b[j]) {
                out = true;
            }

            cerr << "(" << m[j] - b[j] << "," << w[j] << ") ";
        }
        cerr << endl;
        
        if (T[i] == 'D' && m[2] + b[0] - w[0] > 1) w[0] += 1;
        if (T[i] == 'L' && m[3] + b[1] - w[1] > 1) w[1] += 1;
        if (T[i] == 'U' && m[0] + b[2] - w[2] > 1) w[2] += 1;
        if (T[i] == 'R' && m[1] + b[3] - w[3] > 1) w[3] += 1;
        
        
        if (out) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    
    return 0;
}
