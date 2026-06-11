#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, P;
    string S;
    cin >> N;
    vector<tuple<string, int, int>> p;
    rep(i,N) {
        cin >> S >> P;
        p.push_back(make_tuple(S, -P, i + 1));
    }
    sort(p.begin(), p.end());
    for (auto t : p) {
        cout << get<2>(t) << endl;
    }
}
