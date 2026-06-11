#include <bits/stdc++.h>
using namespace std;

int main(){
    long N, K;
    cin >> N >> K;
    long ans = (N / K) * (N / K) * (N / K);
    if(!(K & 1)) ans += ((N + K / 2) / K) * ((N + K / 2) / K) * ((N + K / 2) / K);
    cout << ans << endl;
    return 0;
}