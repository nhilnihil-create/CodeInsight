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

map<char, set<int>> froms;
map<char, set<int>> tos;

int main(void) {
    string S, T;
    cin >> S >> T;
    const int slen = (int) S.size();

    for (int i = 0; i < slen; i++) {
        froms[S[i]].insert(T[i]);
        tos[T[i]].insert(S[i]);
    }

    bool ok = true;

    for (auto p :froms) {
        const int n = (int) p.second.size();
        // printf("froms %c: %d\n", p.first, n);
        if (n > 1) {
            ok = false;
        }
    }
    for (auto p : tos) {
        const int n = (int) p.second.size();
        // printf("tos %c: %d\n", p.first, n);
        if (n > 1) {
            ok = false;
        }
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
