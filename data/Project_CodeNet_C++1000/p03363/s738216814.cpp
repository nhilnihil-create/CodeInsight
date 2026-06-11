#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;  cin >> n;
    vector<long long> a(n), s(n+1, 0);
    map<long long, long long> m;
    m[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
        m[s[i+1]]++;
    }

    long long ans = 0;
    for (auto itr: m) {
        long long c = itr.second;
        ans += c*(c-1)/2;
    }
    cout << ans << endl;
    return 0;
}