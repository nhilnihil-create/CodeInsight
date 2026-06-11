#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> l, r;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        l.push_back(b);
        r.push_back(a);
    }

    l.push_back(0);
    r.push_back(0);
    N++;

    sort(begin(l), end(l));
    sort(begin(r), end(r));
    reverse(begin(r), end(r));

    long long result = 0;
    for (int i = 0; i < N && l[i] < r[i]; i++) {
        result += 2 * (r[i] - l[i]);
    }
    cout << result << endl;
}
