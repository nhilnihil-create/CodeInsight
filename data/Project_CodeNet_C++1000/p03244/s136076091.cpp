#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int

int main() {
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> occ(100001, 0);
    vector<pair<int, int>> evens, odds;
    for (int i = 1; i <= n - 2; i += 2) {
        occ[arr[i]]++;
    }
    occ[arr[n - 1]]++;

    for (int i = 0; i < 100001; i++) {
        if (occ[i]) odds.push_back({occ[i], i});
    }

    sort(odds.begin(), odds.end(), greater<pair<int, int>>());

    for (int i = 0; i < 100001; i++) occ[i] = 0;

    for (int i = 2; i <= n - 2; i += 2) {
        occ[arr[i]]++;
    }
    occ[arr[n]]++;
    for (int i = 0; i < 100001; i++) {
        if (occ[i]) evens.push_back({occ[i], i});
    }

    sort(evens.begin(), evens.end(), greater<pair<int, int>>());

    /*
    for (auto p : odds) {
        cout << p.second << " occ " << p.first << endl;
    }
    cout << "----" << endl;
    for (auto p : evens) {
        cout << p.second << " occ " << p.first << endl;
    }
    */

    if (evens[0].second == odds[0].second) {
        int evens1 = evens[0].first, odds1 = odds[0].first, evens2, odds2;
        
        if (evens.size() <= 1) evens2 = 0;
        else evens2 = evens[1].first;

        if (odds.size() <= 1) odds2 = 0;
        else odds2 = odds[1].first;

        int ans = min(n - evens1 - odds2, n - evens2 - odds1);

        cout << ans << endl;
    } else {
        int ans = (n / 2 - evens[0].first) + (n / 2 - odds[0].first);
        cout << ans << endl;
    }
}
