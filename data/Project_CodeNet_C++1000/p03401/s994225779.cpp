#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;

 int main() {
     ll N, sum = 0;
     cin >> N;

     vector<ll> A(N + 2, 0);

     rep(i, 1, N + 1) cin >> A.at(i);

     rep(i, 0, N + 1) sum += abs(A.at(i + 1) - A.at(i));

     rep(i, 1, N + 1) cout << sum - abs(A.at(i) - A.at(i - 1)) - abs(A.at(i + 1) - A.at(i)) + abs(A.at(i + 1) - A.at(i - 1)) << endl;
 }
