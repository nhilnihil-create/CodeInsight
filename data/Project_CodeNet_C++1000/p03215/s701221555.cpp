#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
using namespace std;
int main(){
    long long N, K;
    cin >> N >> K;
    vector<long long> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    vector<long long> sum(N + 1, 0);
    for(int i = 1; i < N + 1; i++) sum[i] = sum[i - 1] + a[i - 1];
    vector<long long> bit(45, 0);
    vector<long long> t;
    for(int i = 1; i < N + 1; i++){
        for(int j = 0; j < i; j++){
            long long temp = sum[i] - sum[j];
            t.push_back(temp);
            int c = 0;
            while(temp > 0){
                if(temp & 1) bit[c]++;
                temp >>= 1;
                c++;
            }
        }
    }
    long long ans = 0;
    while(1){
        long long ind = 0;
        vector<long long> res;
        vector<long long> tbit(45, 0);
        int flag = 0;
        for(int i = 0; i < 45; i++){
            if(bit[44 - i] >= K) {
                ind = 44- i;
                ans ^= (1LL << ind);
                flag = 1;
                break;
            }
        }
        if(flag == 0) break;
        for(int i = 0; i < t.size(); i++){
            if(t[i] & (1LL << ind)){
                t[i] ^= (1LL << ind);
                res.push_back(t[i]);
            }
        }
        for(int i = 0; i < res.size(); i++){
            long long s = res[i];
            long long c = 0;
            while(s > 0){
                if(s & 1) tbit[c]++;
                s >>= 1;
                c++;
            }
        }
        t = res;
        bit = tbit;
    }
    cout << ans << endl;
}