#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int ans = 0;
    for (int i = 0; i < N - 1; ++i) {
        set<char> left, right, intersection;
        for (int l = 0; l <= i; ++l) left.insert(S[l]);
        for (int r = i + 1; r < N; ++r) right.insert(S[r]);
        set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(intersection, intersection.end()));
        int tmp = intersection.size();
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}
