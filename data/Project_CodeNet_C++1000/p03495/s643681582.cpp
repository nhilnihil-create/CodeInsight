#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> num(0);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    num.push_back(1);
    for (int i = 1; i < n; i++) {
        if (a.at(i - 1) == a.at(i)) {
            num.at(num.size() - 1)++;
        }
        else num.push_back(1);
    }
    sort(num.begin(), num.end());
    int ans = 0;
    if (num.size() <= k) {
        cout << ans << endl;
        return 0;
    }
    else {
        for (int i = 0; i < num.size() - k; i++) {
            ans += num.at(i);
        }
        cout << ans << endl;
        return 0;
    }
}