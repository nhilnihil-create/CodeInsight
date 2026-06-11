#include <bits/stdc++.h>
using namespace std;

void print() { cout << endl; }
template <typename Head, typename... Tail>
void print(Head head, Tail... tail) {
    int size = sizeof...(Tail);
    cout << head;
    if (size > 0) {
        cout << " ";
    }
    print(tail...);
}

void print0() {}
template <typename Head, typename... Tail>
void print0(Head head, Tail... tail) {
    cout << head;
    print0(tail...);
}
int main() {
    int64_t N, M;
    cin >> N;
    cin >> M;

    vector<pair<int64_t, int64_t>> alledg;
    map<int64_t, vector<int64_t>> edg;
    for (int64_t i = 0; i < M; i++) {
        int64_t a, b;
        cin >> a;
        cin >> b;
        a--;
        b--;
        edg[a].push_back(b);
        edg[b].push_back(a);
        alledg.push_back(make_pair(a, b));
    }
    vector<int64_t> colors(N);
    for (int64_t i = 0; i < N; i++) {
        colors[i] = -1;
    }
    colors[0] = 1;

    bool twocolor = true;
    stack<int64_t> nodeids;
    nodeids.push(0);
    while (!nodeids.empty()) {
        int64_t nod = nodeids.top();
        nodeids.pop();
        for (auto dstnod : edg[nod]) {
            if (colors[dstnod] == -1) {
                colors[dstnod] = 1 - colors[nod];
                nodeids.push(dstnod);
            } else if (colors[dstnod] == colors[nod]) {
                twocolor = false;
            }
        }
    }

    if (twocolor) {
        int64_t p = 0;
        int64_t q = 0;
        for (auto c : colors) {
            if (c == 0) {
                p++;
            } else {
                q++;
            }
        }
        cout << (p * q - M) << endl;

    } else {
        cout << ((N * (N - 1) / 2) - M) << endl;
    }
}
