#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <random>

using namespace std;

int solve(vector<int> f, vector<int> s, int st, int len) {
    // cerr << "solve " << len << ' ' << st << endl;
    // for (auto t : f) {
    //     cerr << t << ' ';
    // }
    // cerr << endl;
    // for (auto t : s) {
    //     cerr << t << ' ';
    // }
    // cerr << endl;
    int n = (int)f.size();
    auto can_l = [&](int x) {
        int cp = x;
        for (int i = 0; i < n; i++) {
            if (f[i] == -1) {
                cp--;
                if (cp < 0) return true;
            }
            if (s[i] == 1) {
                cp++;
                cp = min(cp, len - 1);
            }
        }
        return false;
    };
    auto can_r = [&](int x) {
        int cp = x;
        for (int i = 0; i < n; i++) {
            if (f[i] == 1) {
                cp++;
                if (cp >= len) return true;
            }
            if (s[i] == -1) {
                cp--;
                cp = max(cp, 0);
            }
        }
        return false;
    };
    cerr << can_l(st) << ' ' << can_r(st) << endl;  
    return can_l(st) || can_r(st);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w, n;
    cin >> h >> w >> n;
    int r, c;
    cin >> r >> c;
    r--;
    c--;
    string s, t;
    cin >> s >> t;
    {
        vector<int> a;
        vector<int> b;
        map<char, int> keks;
        keks['U'] = -1;
        keks['D'] = 1;
        for (int i = 0; i < n; i++) {
            a.push_back(keks[s[i]]);
            b.push_back(keks[t[i]]);
        }
        if (solve(a, b, r, h)) {
            cout << "NO\n";
            return 0;
        }
    }
    {
        vector<int> a;
        vector<int> b;
        map<char, int> keks;
        keks['L'] = -1;
        keks['R'] = 1;
        for (int i = 0; i < n; i++) {
            a.push_back(keks[s[i]]);
            b.push_back(keks[t[i]]);
        }
        if (solve(a, b, c, w)) {
            cout << "NO\n";
            return 0;
        }
    } 
    cout << "YES\n";
}   
