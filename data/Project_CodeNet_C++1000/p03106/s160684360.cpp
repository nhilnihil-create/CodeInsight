#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    vector<int> ans(101);

    for (int i = 1; i <= 100; i++) {
        if (A % i == 0 && B % i == 0) ans.push_back(i);
    }
    sort(ans.begin(), ans.end(), greater<int>());
    cout << ans.at(K - 1) << endl;
}