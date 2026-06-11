#include<bits/stdc++.h>
using namespace std;
                    
                    
int main(){
    long long N, K, n;
    long long ans = 99999999999;
    cin >> N >> K;
    vector<long long> h;
    for(int i = 0; i < N; i++){
        cin >> n;
        h.push_back(n);
    }
    K -= 1;

    sort(h.begin(), h.end());

    for(int i = K; i < N; i++){
        ans = min(h[i] - h[i - K], ans);
    }

    cout << ans << endl;

    return 0;
}