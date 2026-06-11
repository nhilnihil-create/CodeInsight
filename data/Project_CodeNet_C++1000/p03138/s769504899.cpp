#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long N, K;
    cin >> N >> K;
    long long tk = K + 1;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<int> bit(40, 0);
    long long ans = 0;
    vector<int> bi(40, 0);
    for(int i = 0; i < N; i++){
        int c = 0;
        long long a = A[i];
        while(a > 0){
            if(a % 2 == 1) bi[c]++;
            c++;
            a >>= 1;
        }
    }
    K++;
    int cnt = 0;
    while(K > 0){
        if(K % 2 == 1) bit[cnt]++;
        cnt++;
        K >>= 1;
    }
    for(int i = 0; i < 40; i++){
        if(bit[i] == 1){
            long long t = tk & (~(1LL << i));
            for(int j = 0; j < i; j++){
                if(bi[j] > N - bi[j]) t &= (~(1LL << j));
                else t |= (1LL << j);
            }
            long long res = 0;
            for(int j = 0; j < N; j++) res += A[j]^t;
            ans = max(ans, res);
        }
    }
    cout << ans << endl;
}