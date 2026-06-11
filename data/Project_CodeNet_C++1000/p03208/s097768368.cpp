#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(_) cerr << #_ << ": " << (_) << '\n'
#define _GLIBCXX_DEBUG
#else
#define debug(_) 0
#endif // LOCAL

int main(){
    int N, K;
    vector<int> hs;

    cin >> N >> K;
    hs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> hs[i];
    }

    sort(hs.begin(), hs.end());
    K--;
    int ans = 1001001001;
    for (int i = K; i < N; i++) {
        ans = min(ans, hs[i] - hs[i-K]);
    }

    cout << ans << '\n';

    return 0;
}