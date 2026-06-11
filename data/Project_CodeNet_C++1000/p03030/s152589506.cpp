#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n; cin >> n;
    vector<tuple<string, int, int>> R(n);
    rep(i, n) {
        cin >> get<0>(R.at(i)) >> get<1>(R.at(i));
        get<2>(R.at(i)) = i + 1;
        get<1>(R.at(i)) *= -1;
    }

    sort(R.begin(), R.end());
    rep(i, n) cout << get<2>(R.at(i)) << endl;
}