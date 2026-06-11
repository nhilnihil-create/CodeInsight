#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;
const double PI=3.14159265358979323846;

int main() {
    long long A, B;
    cin >> A >> B;

    long long cnt = B - A + 1;

    if (cnt & 0x1) {
        long long n = (cnt - 1) / 2;
        long long b = (A & 0x1) ? A : B;
        if (n & 0x1) {
            cout << (0x1 ^ b) << endl;
        } else {
            cout << b << endl;
        }
    } else {
        if (A & 0x1) {
            long long n = cnt / 2 - 1;
            if (n & 0x1) {
                cout << (A ^ 1 ^ B) << endl;
            } else {
                cout << (A ^ B) << endl;
            }
        } else {
            long long n = cnt / 2;
            if (n & 0x1) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }   

/*
    long long ans = A;
    for (long long i = A + 1; i <= B; ++i) {
        ans = ans ^ i;
    }
    cout << ans << endl;
*/

    return 0;
}
