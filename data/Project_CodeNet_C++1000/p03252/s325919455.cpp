#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;



int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    auto encode = [&](string& s) {
        char ch = 'a';
        vector<char> M(128, -1);

        string res;
        for (auto c : s) {
            if (M[c] == -1) {
                M[c] = ch++;
            }
            res += M[c];
        }
        return res;
    };
    auto check = [&](string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n != m) {
            return false;
        }


        if (encode(s) != encode(t)) {
            return false;
        }

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // s.resize(unique(s.begin(), s.end()) - s.begin());
        // t.resize(unique(t.begin(), t.end()) - t.begin());
        // if (s != t) {
        //     return false;
        // }

        return true;
    };

    if (check(s, t)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}