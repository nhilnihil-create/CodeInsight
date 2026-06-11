#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K, H[100000];
    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> H[i];
    sort(H, H+N);
    
    int ans = 2e9;
    for(int i=0; i<=N-K; i++) ans = min(ans, H[i+K-1] - H[i]);
    cout << ans << endl;
    return 0;
}
