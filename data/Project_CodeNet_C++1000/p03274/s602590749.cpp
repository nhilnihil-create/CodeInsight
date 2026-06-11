#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    vector<int>x(N);
    for(int i = 0; i < N; i++) {
        cin >> x[i];
    }
    int ans = 1e9;
    for(int i = 0; i < N-K+1; i++) {
        int hidari = x[i];
        int migi = x[i+K-1];
        int hajime = min(abs(0-hidari),abs(0-migi));
        ans = min(ans,migi-hidari+hajime);
    }
    cout << ans << endl;
}
