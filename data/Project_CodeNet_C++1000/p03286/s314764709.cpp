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

int main(void) {
    int N;
    cin >> N;

    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> bits;

    while (N != 0) {
        if ((N & 0x1) != 0) {
            bits.push_back(1);
            N -= 1;
        } else {
            bits.push_back(0);
        }
        N /= -2;
    }

    reverse(bits.begin(), bits.end());

    for (auto b : bits) {
        cout << b;
    }
    cout << endl;

    return 0;
}
