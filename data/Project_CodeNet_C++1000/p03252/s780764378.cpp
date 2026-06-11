#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string s, t;
    int n;
    cin >> s >> t;
    vector<int> start(26, -1);
    vector<int> goal(26, -1);

    n = s.size();
    for (int i = 0; i < n; i++) {
        int a = s[i] - 'a';
        int b = t[i] - 'a';
        if (start[a] == -1 && goal[b] == -1) {
            start[a] = b;
            goal[b] = a;
        } else {
            if (start[a] != b || goal[b] != a) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
