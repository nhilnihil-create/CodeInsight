#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    set<int> as;
    map<int, int> am;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        as.insert(a[i]);
    }

    sort(a.begin(), a.end());

    for(auto itr = as.begin(); itr != as.end(); itr++) {
        int num = upper_bound(a.begin(), a.end(), *itr) -
                  lower_bound(a.begin(), a.end(), *itr);


        am.insert(make_pair(*itr, num));          
    }

    int ans = 0;
    for (auto itr = am.begin(); itr != am.end(); itr++) {
        if(itr->first != itr->second) {
            if(itr->second > itr->first) {
                ans += itr->second - itr->first;
            } else {
                ans += itr->second;
            }
        }
    }

    cout << ans << endl;
}