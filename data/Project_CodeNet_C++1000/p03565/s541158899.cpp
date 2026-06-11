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
    string s, t;
    cin >> s >> t;
    int n1 = s.size(), n2 = t.size();
    vector<string> res;
    for (int i = 0; i + n2 <= n1; i++) {
        string ss = s;
        int flag = 1;
        for (int j = 0; j < n2; j++) {
            if (ss[j + i] == '?' || ss[j + i] == t[j]) {
                ss[j + i] = t[j];
            } else {
                flag = 0;
                break;
            }
        }
        if (flag == 0) continue;
        for (int j = 0; j < n1; j++) {
            if (ss[j] == '?') ss[j] = 'a';
        }
        res.push_back(ss);
    }
    if (res.size() == 0) {
        cout << "UNRESTORABLE" << endl;
    } else {
        sort(res.begin(), res.end());
        cout << res[0] << endl;
    }
}


