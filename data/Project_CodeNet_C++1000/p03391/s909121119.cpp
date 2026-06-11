#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    bool is_equal = true;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a.at(i) >> b.at(i);
        sum += a.at(i);
        is_equal &= a.at(i) == b.at(i);
    }
    
    if (is_equal) {
        cout << 0 << endl;
        return 0;
    }

    long long maxi = 0;
    for (int i = 0; i < n; i++) {
        if (a.at(i) > b.at(i)) maxi = max(maxi, sum - b.at(i));
    }
    cout << maxi << endl;
}