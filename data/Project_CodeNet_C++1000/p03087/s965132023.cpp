#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N, Q;
    string S;
    cin >> N >> Q >> S;
    vector<int> l(Q), r(Q);
    rep(i,Q) {
        cin >> l.at(i) >> r.at(i);
    }
    vector<int> count(N+1,0);
    int sum = 0;
    for (int i = 1; i < N; ++i) {
        if (S.at(i-1) == 'A' && S.at(i) == 'C') ++sum;
        count.at(i+1) = sum;
    }
    rep(i,Q) {
        cout << count.at(r.at(i)) - count.at(l.at(i)) << endl;
    }
}
