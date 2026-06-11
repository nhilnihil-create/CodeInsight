#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int main() {
    int N;
    cin >> N;
    vector<P> v(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = P(b, a);
    }
    vector<P> w(N);
    for (int i = 0; i < N; i++) {
        int c, d;
        cin >> c >> d;
        w[i] = P(c, d);
    }
    sort(v.begin(), v.end(), greater<P>());
    sort(w.begin(), w.end());
    vector<bool> check(N, false);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!check[j] && v[j].second < w[i].first &&
                v[j].first < w[i].second) {
                check[j] = true;
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
}