#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    vector<int> time(N-K+1);
    for(int i = 0; (i+K-1) < N; i++){
        int left = i;
        int right = i+K-1;
        time[left] = a[right] - a[left];
        time[left] += min(fabs(a[left]), fabs(a[right]));
    }
    sort(time.begin(), time.end());
    int ans = time[0];

    cout << ans << endl;
    return 0;
}