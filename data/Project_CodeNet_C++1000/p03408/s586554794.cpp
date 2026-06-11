#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    vector<string> s, t;

    cin >> n;
    s = vector<string>(n);
    for (int i = 0; i < n; i++) {
        cin >> s.at(i);
    }

    cin >> m;
    t = vector<string>(m);
    for (int i = 0; i < m; i++) {
        cin >> t.at(i);
    }

    int max_score, score;
    string w;
    max_score = 0;
    for (int i = 0; i < n; i++) {
        score = 0;
        w = s.at(i);
        for (int j = 0; j < n; j++) {
            if (w == s.at(j)) score += 1;
        }
        for (int j = 0; j < m; j++) {
            if (w == t.at(j)) score -= 1;
        }
        if (score > max_score) max_score = score;
    }
    cout << max_score << endl;
}
