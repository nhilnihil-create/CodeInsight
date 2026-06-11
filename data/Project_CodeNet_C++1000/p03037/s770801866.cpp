#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> l(M);
    vector<int> r(M);
    for (int i = 0; i < M; i++) {
        cin >> l.at(i) >> r.at(i);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int cnt = 0;
    for (int i = l.at(M-1); i <= r.at(0); i++) {
        cnt++;
    }
    cout << cnt << endl;
}