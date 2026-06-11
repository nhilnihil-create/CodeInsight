#include <iostream>
#include <vector>
#include <string> 
#include <algorithm>
#include <set>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<long long> cnt(K);
    for(int i = 1; i <= N; i++){
        cnt[i % K]++;
    }
    long long ans = 0;
    for(int i = 1; i <= N; i++){
        if((K - i % K) % K * 2 % K != 0) continue;
        ans += cnt[(K - i % K) % K] * cnt[(K - i % K) % K];
    }
    cout << ans << endl;
}