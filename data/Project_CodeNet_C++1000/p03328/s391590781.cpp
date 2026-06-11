#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a,b;
    cin >> a >> b;
    int n = b - a;
    int sum = 0;
    for (int i = 1; i<=n; ++i) sum+=i;
    cout << sum - b << endl;
    return 0;
}