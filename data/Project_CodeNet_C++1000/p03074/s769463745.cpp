#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

string s;

// for 1s
vector<int> ls;
// for 0s
vector<int> rs;

int main(void) {
    int N, K;
    cin >> N >> K;

    cin >> s;

    if (s[0] == '0') {
        ls.push_back(0);
    }

    {
        int pos = 1;
        int cnt = 1;
        char prev = s[0];
        while (pos < N) {
            if (s[pos] == prev) {
                cnt++;
            } else {
                if (prev == '0') {
                    rs.push_back(cnt);
                } else {
                    ls.push_back(cnt);
                }
                prev = s[pos];
                cnt = 1;
            }
            pos++;
        }
        if (prev == '0') {
            rs.push_back(cnt);
        } else {
            ls.push_back(cnt);
        }
    }

    if (s[N - 1] == '0') {
        ls.push_back(0);
    }

#ifdef DEBUG
    printf("ls: \n");
    for (auto x : ls) {
        cout << x << " ";
    }
    cout << endl;

    printf("rs: \n");
    for (auto x : rs) {
        cout << x << " ";
    }
    cout << endl;
#endif

    if ((int) rs.size() <= K) {
        // can satisfy all people
        cout << N << endl;
        return 0;
    }

    int acc = 0;
    for (int i = 0; i < K; i++) {
        acc += ls[i];
        acc += rs[i];
    }
    acc += ls[K];

    int ans = acc;
    for (int i = K; i < (int) rs.size(); i++) {
        acc -= ls[i - K];
        acc -= rs[i - K];
        acc += ls[i + 1];
        acc += rs[i];
        chmax(ans, acc);
    }

    cout << ans << endl;

    return 0;
}
