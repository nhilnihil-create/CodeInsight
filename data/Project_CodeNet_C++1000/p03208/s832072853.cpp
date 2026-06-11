#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define reps(i,s,n) for (int i = (s); i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {

    int N, K;
    cin >> N >> K;
    int h[N];
    for(int i = 0; i < N; i++){
        cin >> h[i];
    }
    sort(h, h+N);
    int min_diff = 1e9;
    for(int i = 0; i <= N - K; i++){
        int diff = h[i + (K - 1)] - h[i];
        min_diff = min(min_diff, diff);
    }
    cout << min_diff << endl;

    return 0;
}