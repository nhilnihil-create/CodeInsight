#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<long long> sum(N + 1), sumxor(N + 1);
    for(int i = 0; i < N; i++){
        sum[i + 1] = sum[i] + A[i];
        sumxor[i + 1] = sumxor[i] ^ A[i];
    }
    int l = 0, r = 0;
    long long ans = 0;
    for(l = 0; l <= N; l++){
        if(l == r) r++;
        while(r <= N){
            long long t = sumxor[r] ^ sumxor[l];
            if(t != sum[r] - sum[l]) break;
            ans += r - l;
            r++;
        }
    }
    cout << ans << endl;
}