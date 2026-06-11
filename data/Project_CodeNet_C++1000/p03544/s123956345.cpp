#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N; cin >> N;
    vector<ll> lucas(100);
    lucas[0] = 2; lucas[1] = 1;
    for(int i = 2; i < 100; i++) {
        lucas[i] = lucas[i - 1] + lucas[i - 2];
    }
    cout << lucas[N] << endl;
    return 0;
}