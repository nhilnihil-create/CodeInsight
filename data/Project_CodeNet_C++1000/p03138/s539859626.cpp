#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>

using namespace std;

int main(){

    long long N, K;
    cin >> N >> K;

    vector<long long> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    vector<int> cnt0(40, 0);
    vector<int> cnt1(40, 0);

    for(long long temp: A){
        for(int i = 0; i < 40; i++){
            if(temp & (1LL << i)){
                cnt1[i]++;
            }
            else{
                cnt0[i]++;
            }
        }
    }

    vector<long long> bestSum(40);
    bestSum[0] = 0;
    for(int i = 1; i < 40; i++){
        long long plus;
        if(cnt1[i - 1] > cnt0[i - 1]){
            plus = cnt1[i - 1] * (1LL << (i - 1));
        }
        else{
            plus = cnt0[i - 1] * (1LL << (i - 1));
        }

        bestSum[i] = bestSum[i - 1] + plus;
    }

    long long tempSum = 0;
    long long ans = 0;
    for(int i = 39; i >= 0; i--){
        if(K & (1LL << i)){
            // 0, K未満確定
            long long temp = tempSum + cnt1[i] * (1LL << i) + bestSum[i];
            ans = max(ans, temp);

            // 1
            tempSum += cnt0[i] * (1LL << i);
        }
        else{
            // 0
            tempSum += cnt1[i] * (1LL << i);
        }
    }
    ans = max(ans, tempSum);

    cout << ans << endl;

    return 0;
}