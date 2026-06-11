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
    int N; cin >> N;
    vector<int> A(N);
    int M = 0, m = inf;
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        M = max(M, A.at(i));
        m = min(m, A.at(i));
    }
    cout << M - m << endl;
    return 0;
}