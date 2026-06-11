#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    vector<pair<int,int>> V(N);

    rep(i,N) {
        int a, b; cin >> a >> b;
        V[i] = {a,b};
    }
    sort(V.begin(), V.end(), [](auto&& a, auto&& b){
        return (a.first + a.second) > (b.first + b.second);
    });
    ll sumA = 0, sumB = 0;
    rep(i,N) {
        if (i % 2 == 0) sumA += V[i].first; else sumB += V[i].second;
    }
    cout << sumA - sumB << endl;
}
