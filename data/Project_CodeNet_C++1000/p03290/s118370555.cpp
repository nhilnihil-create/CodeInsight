#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int MAX = 1e9;
int d, g;
vector<int> p;
vector<int> c;

int solve(int next, int remain, vector<pair<int, int>> &problems) {
    if (next == d) {
        for (int i = problems.size()-1; i >= 0; i--) {
            int point = problems[i].first;
            int numprob = problems[i].second;
            if (point * numprob >= remain) {
                return ceil(1.0 * remain / point);
            }
        }
        return MAX;
    } else {
        int point = next + 1;
        int avail_p = p[next] * point + c[next];
        int when_complete = MAX;
        if (remain > avail_p) {
            when_complete = p[next] + solve(next + 1, remain - avail_p, problems);
        } else if (remain <= avail_p) {
            when_complete = p[next];
        }
        problems.emplace_back(point, p[next] - 1);
        int when_incomplete = solve(next + 1, remain, problems);
        problems.pop_back();
        return min(when_complete, when_incomplete);
    }
}

int main() {
    cin >> d >> g;
    g /= 100;
    for (int i = 0; i < d; i++) {
        int pp, cc;
        cin >> pp >> cc;
        cc /= 100;
        p.push_back(pp);
        c.push_back(cc);
    }

    vector<pair<int, int >> problems;
    int result = solve(0, g, problems);
    cout << result << endl;
}
