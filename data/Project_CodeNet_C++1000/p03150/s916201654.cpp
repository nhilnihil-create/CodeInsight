#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
    string s;
    string ans = "keyence";
    cin >> s;
    int n1 = s.size(), n2 = ans.size();
    int res = 0;
    for (int i = 0; i < n1 && i < n2; i++) {
        if (s[i] == ans[i]) {
            res++;
        } else {
            break;
        }
    }
    for (int i = 0; i < n1 && i < n2; i++) {
        if (s[n1 - 1 - i] == ans[n2 - 1- i]) {
            res++;
        } else {
            break;
        }
    }
    if (res >= n2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}


