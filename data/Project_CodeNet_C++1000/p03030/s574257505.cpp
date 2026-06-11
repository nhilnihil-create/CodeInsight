#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<pair<string, int>, int>> vec_p(N);
    pair<pair<string, int>, int> p;

    for (int i = 0; i < N; i++) {
        string s;
        int score;

        cin >> s >> score;
        p = make_pair(make_pair(s, -score), i + 1);

        vec_p.at(i) = p;
    }

    sort(vec_p.begin(), vec_p.end());

    for (int i = 0; i < N; i++) {
        int ans;
        ans = vec_p.at(i).second;
        cout << ans << endl;
    }
}
