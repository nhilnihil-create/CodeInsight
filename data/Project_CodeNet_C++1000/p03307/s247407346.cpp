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

int gcd(int n, int m) {
    if (n < m) swap(n, m);
    if (n % m == 0) return m;
    return gcd(m, n % m);
}

int lcm(int n, int m) {
    return (n * m) / gcd(n, m);
}

int main() {
    int N; cin >> N;
    cout << lcm(2, N) << endl;
}