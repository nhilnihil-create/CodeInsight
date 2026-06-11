#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;
int64_t calc(int64_t N) {
    int divN = (((N+1) / 2) % 2);
    if(N % 2 == 1) {
        return divN;
    } else {
        return N ^ divN;
    }
}

int main() {
    int64_t A, B;
    cin >> A >> B;
    if(A == 0) {
        cout << calc(B) << endl;
        return 0;
    }

    cout << (calc(A-1) ^ calc(B)) << endl;

    return 0;
}

