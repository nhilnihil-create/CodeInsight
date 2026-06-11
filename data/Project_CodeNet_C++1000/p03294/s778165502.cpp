#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int MOD = 1000000007;

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    ll out = 0;
    for (int i = 0; i < N; i++){
      out += a[i] - 1;
    }
    cout << out << endl;
    return 0;
}