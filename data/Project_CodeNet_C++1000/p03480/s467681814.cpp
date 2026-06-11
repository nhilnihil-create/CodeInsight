#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX (1123456789)

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> sep;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != s[i])sep.push_back(i);
    }
    int k = n;
    for (int i = 0; i < sep.size(); i++) {
        int l = max(n - sep[i], sep[i]);
        k = min(k, l);
    }
    cout << k << endl;
}
