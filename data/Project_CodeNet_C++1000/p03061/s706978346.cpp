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

int gcd(int x, int y) {
    if (x > y) {
        swap(x, y);
    }
    if (x <= 0) {
        return y;
    }
    return gcd(y % x, x);
}

vector<int> as;

// ls[i] is gcd of as in [0, i)
vector<int> ls;
// rs[i] is gcd of as in [i, N)
vector<int> rs;

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    ls.resize(N + 1);
    ls[0] = 0;
    for (int i = 0; i < N; i++) {
        ls[i + 1] = gcd(ls[i], as[i]);
    }
#ifdef DEBUG
    printf("ls: \n");
    for (int i = 0; i <= N; i++) {
        cout << ls[i] << " ";
    }
    cout << endl;
#endif

    rs.resize(N + 1);
    rs[N] = 0;
    for (int i = N - 1; i >= 0; i--) {
        rs[i] = gcd(rs[i + 1], as[i]);
    }
#ifdef DEBUG
    printf("rs: \n");
    for (int i = 0; i <= N; i++) {
        cout << rs[i] << " ";
    }
    cout << endl;
#endif

    int ans = 0;
    for (int i = 0; i < N; i++) {
        chmax(ans, gcd(ls[i], rs[i + 1]));
    }
    cout << ans << endl;

    return 0;
}
