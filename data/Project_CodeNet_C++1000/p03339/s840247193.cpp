#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    string S; cin >> S;

    vector<int> left(N);
    vector<int> right(N);

    for (int i = 1; i < N; i++){
        left[i] = left[i -1];
        if (S[i - 1] == 'W')left[i]++;
    }

    for (int i = N - 1; i >= 0; i--){
        right[i] = right[i + 1];
        if (S[i + 1] == 'E')right[i]++;
    }

    int ans = 1001001001;
    rep(i, N){
        int X = left[i] + right[i];
        if (X < ans)ans = X;
    }

    cout << ans << endl;
    
}