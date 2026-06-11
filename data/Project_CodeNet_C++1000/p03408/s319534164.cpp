#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, mx = 0; cin >> N;
    map<string, int> val;
    vector<string> key;
    for (int i = 0; i < N; i++) {
        string x; cin >> x;
        if (val.count(x)) {
            val[x]++;
        } else {
            val[x] = 1;
            key.push_back(x);
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        string x; cin >> x;
        if (val.count(x)) {
            val[x]--;
        } else {
            val[x] = -1;
            key.push_back(x);
        }
    }
    for (int i = 0; i < val.size(); i++) {
        mx = max(mx, val.at(key.at(i)));
    }
    cout << mx << endl;
}