#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    long long hidari=0;
    long long migi=N;
    vector<int> card(N, 1);
    for (long long i=0; i<M; i++) {
        long long L, R;
        cin >> L >> R;
        for (long long i=hidari; i<L-1; i++) card.at(i) = 0;
        for (long long i=R; i<migi; i++) card.at(i) = 0;
        hidari = max(hidari, L-1);
        migi = min(migi,R);
    }
    long long sum = std::accumulate(card.begin(), card.end(), 0);
    cout << sum << endl;
}