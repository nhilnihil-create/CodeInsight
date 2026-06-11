#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int cnt[210000];
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        cnt[a-1]++;
    }
    
    sort(cnt, cnt+N);

    int ans = 0;
    for(int i = 0; i < N - K; i++) {
        ans += cnt[i];
    }
    cout << ans << endl;
}