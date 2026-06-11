#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
    }

    sort(h.begin(), h.end());
    int ans = 1000000000;
    for (int i = N - 1; i >= K - 1; i--)
    {
        int temp = h[i] - h[i - K + 1];
        ans = min(ans, temp);
    }
    cout << ans << endl;
    
  return 0;
}