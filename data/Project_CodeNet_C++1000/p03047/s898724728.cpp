#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;

int main(){
    int N, K;
    cin >> N >> K;
    cout << max(0, N - K + 1) << endl;
    return 0;
}