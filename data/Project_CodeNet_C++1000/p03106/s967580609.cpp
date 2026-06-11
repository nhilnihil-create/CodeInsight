#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    vector<int> dividables;
    for (int i = 1; i <= min(A, B); i++) {
        if (A % i == 0 && B % i == 0) dividables.push_back(i);
    }
    
    reverse(dividables.begin(), dividables.end());

    cout << dividables.at(K - 1) << endl;

    return 0;
}
