#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <functional>
#include <ctime>
#include <cmath>
#include <limits>
#include <numeric>
#include <type_traits>
unsigned euclidean_gcd(unsigned a, unsigned b) {
    if (a < b) return euclidean_gcd(b, a);
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}
using namespace std;

int main() {
    string a;
    cin >> a;
    vector<bool> s(26);
    int f = a.size();
    for (int i = 0; i < f; i++) {
        s.at(a.at(i) - 'a') = true;
    }
    for (int i = 0; i < 26; i++) {
        if (s.at(i) == false) {
            cout << a;
            char t = 'a';
            for (int j = 0; j < i; j++) {
                t += 1;
            }
            cout << t << endl;
            break;

        }
    }
    if (a.size() == 26) {
        for (int i = 25; i > -1; i--) {
            char v = 'Z';
            for (int j = i + 1; j < 26; j++) {
                if (a.at(i) < a.at(j)) {
                    if (v == 'Z')v = a.at(j);
                    else v = min(a.at(j), v);
                }
            }
            if (v != 'Z') {
                for (int j = 0; j < i; j++) {
                    cout << a.at(j);
                }
                cout << v << endl;
                break;
            }
        }
        if (a == "zyxwvutsrqponmlkjihgfedcba")cout << -1 << endl;
    }
}