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

vector<vector<int>> g;

long calc(int i, long s, int p) {
    long res = s;
    for (int x : g[i]) {
        if (x != p)
        res += calc(x, s + 1, i);
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<long, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    std::sort(a.rbegin(), a.rend());

    map<long, int> q;
    for (int i = 0; i < n; i++) {
        q[a[i].first] = i;
    }

    vector<int> s(n);

    g.resize(n);

    for (int i = 0; i < n - 1; i++) {
        s[i]++;
        long p = a[i].first - (n - 2 * s[i]);
        if (p >= a[i].first) {
            cout << -1;
            return 0;
        }
        if (q.find(p) == q.end()) {
            cout << -1;
            return 0;
        }
        int x = q[p];
        s[x] += s[i];
        g[x].push_back(i);
        g[i].push_back(x);
    }

    if (calc(n - 1, 0, -1) != a[n - 1].first) {
        cout << -1;
        return 0;
    }

//    for (int i = 0; i < n; i++) {
//        cerr << a[i] << " "<< calc(i, 0, -1) << "\n";
////        if (calc(i, 0, -1) != a[i]) cerr << "!!!";
//    }

    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            if (j > i)
                cout << (a[i].second + 1) << " " << (a[j].second + 1) << "\n";
        }
    }

    return 0;
}