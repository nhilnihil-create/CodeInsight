#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<tuple<string, int, int>> a;

    for(int i = 1; i <= N; i++) {
        string s;
        int p;
        cin >> s >> p;

        a.push_back(make_tuple(s, -p, i));
    }

    sort(a.begin(), a.end());

    for(tuple<string, int, int> t : a) {
        string s;
        int p;
        int i;

        tie(s, p, i) = t;
        cout << i << endl;
    }

    return 0;
}