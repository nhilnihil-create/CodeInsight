#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> dict;
    for (size_t i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (dict.count(a)) {
            ++dict[a];
        }
        else {
            dict[a] = 1;
        }
    }

    if (dict.size() <= k) cout << 0 << endl;
    else {
        vector<int> counts;
        for (const auto& item : dict) counts.push_back(item.second);
        sort(counts.begin(), counts.end());
        int num = 0;
        for (size_t i = 0; i < dict.size() - k; ++i) {
            num += counts[i];
        }
        cout << num << endl;
    }
    
    return EXIT_SUCCESS;
}