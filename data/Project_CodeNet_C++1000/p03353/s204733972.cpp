#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
vector<T> uni(vector<T> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

int main() {
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();
    vector<string> cand;
    for (int i = 0; i < n; i++) for (int j = 1; j <= k && i + j <= n; j++) {
        cand.emplace_back(s.substr(i, j));
    }
    cout << uni(cand)[k - 1] << endl;
    return 0;
}
