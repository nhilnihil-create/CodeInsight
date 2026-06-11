#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, a, b;
    cin >> N >> M;
    deque<pair<int, int>> I;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        I.emplace_back(make_pair(a, b));
    }

    sort(I.begin(), I.end(), 
    [](const auto &a, const auto &b) {return a.second < b.second;});

    int c = 0;
    int r = -1;
    for (pair<int, int> p : I) {
        if (p.first >= r) {
            c++;
            r = p.second;
        }
    }
    cout << c << endl;
}
