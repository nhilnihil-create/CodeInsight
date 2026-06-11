#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n == 3) {
        cout << "2 5 63" << endl;
    } else if(n == 4) {
        cout << "2 5 20 63" << endl;
    } else if(n == 6) {
        cout << "2 3 25 30 60 90" << endl;
    } else if(n == 19999) {
        vector<int> v;
        for(int i = 1; i <= 15000; i++) {
            if(i % 3 != 0) {
                v.push_back(2 * i);
            }
        }
        for(int i = 1; i <= 9999; i++) {
            v.push_back(3 * i);
        }
        for(auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        int two, three;
        for(int i = 2; i <= 5000; i += 2) {
            three = i;
            two = n - i;
            if(0 <= two && two <= 15000 && two % 3 == 0) {
                break;
            }
        }
        vector<int> v;
        for(int i = 1; i <= two; i++) {
            v.push_back(2 * i);
        }
        for(int i = 1, cnt = 0; i <= 10000 && cnt < three; i++) {
            if(i % 2 != 0) {
                cnt++;
                v.push_back(3 * i);
            }
        }
        for(auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}