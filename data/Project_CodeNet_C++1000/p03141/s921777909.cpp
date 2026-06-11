#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> ti;

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    ti d[n];
    for (int i = 0; i < n; i++) {
        d[i] = make_tuple(a[i] + b[i], a[i], b[i]);
    }
    sort(d, d + n);
    reverse(d, d + n);

    ll ascore = 0, bscore = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) ascore += get<1>(d[i]);
        else bscore += get<2>(d[i]);
    }

    cout << ascore - bscore << endl;
    return 0;
}