#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool shiritori(int n) {
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (find(v.begin(), v.end(), s) != v.end()) {
            return false;
        }
        v.push_back(s);
    }
    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1].back() != v[i].front()) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    if (shiritori(n)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
