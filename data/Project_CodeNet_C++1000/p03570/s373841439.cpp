#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L
#define PI 3.141592653589793238462643383279502884L

#define long long long int

using std::vector;
using std::map;
using std::set;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::cerr;

// @author: pashka

int main() {
    std::ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    map<int, int> last;
    int c = 0;

    vector<int> d(n + 1);
    last[0] = 1;

    for (int i = 0; i < n; i++) {
        c ^= (1 << (s[i] - 'a'));
        d[i + 1] = d[i] + 1;
        if (last[c] > 0) {
            d[i + 1] = std::min(d[i + 1], last[c]);
        }
        for (int j = 0; j < 26; j++) {
            int x = last[c ^ (1 << j)];
            if (x > 0) {
                d[i + 1] = std::min(d[i + 1], x);
            }
        }
        if (last[c] == 0 || last[c] > d[i + 1] + 1)
            last[c] = d[i + 1] + 1;
    }

    cout << d[n] << "\n";

    return 0;
}