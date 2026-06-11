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
    int N, X; cin >> N >> X;
    vector<int> m(N);
    int sum = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> m.at(i);
        sum += m.at(i);
        cnt++;
    }
    sort(m.begin(), m.end());
    while (sum + m.at(0) <= X) {
        sum += m.at(0);
        cnt++;
    }
    cout << cnt << endl;
}