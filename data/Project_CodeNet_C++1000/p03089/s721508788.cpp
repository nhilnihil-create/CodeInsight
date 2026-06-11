#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b.at(i);
        b.at(i)--;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int ind;
        for (int j = 0; j < n - i; j++) {
            if (b.at(j) > j) {
                cout << -1 << endl;
                return 0;
            }
            if (b.at(j) == j) ind = j;
        }
        ans.push_back(ind);
        b.erase(b.begin() + ind);
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) {
        cout << ans.at(i) + 1 << endl;
    }
    return 0;
}