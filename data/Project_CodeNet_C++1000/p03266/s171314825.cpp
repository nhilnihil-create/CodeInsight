#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;

 int main() {
     ll N, K;
     cin >> N >> K;
     if (K % 2 == 1) cout << (N / K) * (N / K) * (N / K) << endl;
     else cout << (N / (K / 2) - N / K) * (N / (K / 2) - N / K) * (N / (K / 2) - N / K) + (N / K) * (N / K) * (N / K) << endl;
 }
