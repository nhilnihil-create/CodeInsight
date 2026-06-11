#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    long long K,N;
    cin >> N >> K;
    vector<long long> H(N);
    for(int i=0; i<N; i++){
        cin >> H[i];
    }

    sort(H.begin(), H.end());

    long long min_h = H[0];
    long long max_h = H[K-1];
    long long ans = max_h - min_h;

    for(int i=0; i+K-1<H.size(); i++){
        long long val = H[i+K-1] - H[i];
        if(val < ans){
            ans = val;
        }
    }
    
    cout << ans << endl;
    return 0;
}