#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    unordered_map<int, int> x;
    for (int i = 0; i < N; i++) {
        if (x.count(a.at(i))) {
            x.at(a.at(i))++;
        } else {
            x[a.at(i)] = 1;
        }
    }

    int good = 0;
    for (auto itr = x.begin(); itr != x.end(); itr++) {
        if ((*itr).first <= (*itr).second) {
            good += (*itr).second - (*itr).first;
        } else {
            good += (*itr).second;
        }
    }

    cout << good << endl;
}