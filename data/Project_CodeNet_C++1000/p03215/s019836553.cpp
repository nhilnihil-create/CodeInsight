#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<long long> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    vector<long long> kumi, sum(N + 1, 0);
    for(int i = 1; i < N + 1; i++){
        sum[i] = sum[i - 1] + a[i - 1]; 
    }
    for(int i = 1; i < N + 1; i++){
        for(int j = 0; j < i; j++) kumi.push_back(sum[i] - sum[j]);
    }
    long long ans = 0;
    long long u = 39, b = 2;
    long long temp = 1;
    while(u > 0){
        if(u & 1) temp *= b;
        b *= b;
        u >>= 1;
    }
    for(int k = 0; k < 40; k++){
        long long res = ans + temp;
        int cnt = 0;
        for(int i = 0; i < kumi.size(); i++){
            if((res & kumi[i]) == res) cnt++;
        }
        if(cnt >= K) ans += temp;
        temp /= 2;
    }
    cout << ans << endl;
}