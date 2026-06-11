#include <bits/stdc++.h>
using namespace std;

int d, g;
vector<int> ps;
vector<int> cs;
vector<int> ss;

int solve(int, int, int, int, vector<bool> &);

int main() {
    cin >> d >> g;

    for (int i = 0; i < d; i++) {
        int p, c;
        cin >> p >> c;
        ps.push_back(p);
        cs.push_back(c);
        ss.push_back(c + 100 * (i + 1) * p);
    }

    vector<bool> solved(d);
    cout << solve(0, 0, 0, accumulate(ps.begin(), ps.end(), 0), solved) << endl;
}

int solve(int i, int score, int n, int ans, vector<bool> &solved) {
    if (i > d) return ans;
    if (score >= g) {
        ans = n;
    }

    if (i == d) {
        for (int j = d - 1; j >= 0; j--) {
            if (!solved.at(j)) {
                for (int k = 0; k < ps.at(j); k++) {
                    n++;
                    score += 100 * (j + 1);
                    if (score >= g) break;
                }
            }
            if (score >= g) {
                if (ans > n) ans = n;
                break;
            }
        }
    } else {
        solved.at(i) = false;
        int ans1 = solve(i + 1, score, n, ans, solved);

        solved.at(i) = true;
        int ans2 = solve(i + 1, score + ss.at(i), n + ps.at(i), ans, solved);

        return min(ans1, ans2);
    }
    return ans;
}