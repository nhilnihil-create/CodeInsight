#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

int main() {
    int A, B, K; cin >> A >> B >> K;
    for (int i = A; i <= B; i++) {
        if (i < A + K || i > B - K) cout << i << endl;
    }
    return 0;
}