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
    int D, N; cin >> D >> N;
    vector<int> ans;
    for (int i = 1; i < 10000000; i++) {
        if (i % (int)pow(100, D) == 0 && i % (int)pow(100, D + 1) != 0) ans.push_back(i);
    }
    cout << ans.at(N - 1) << endl;
}