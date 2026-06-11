#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int deg[5];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 3; i++) {
        int a, b; cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    int numOdd = 0;
    for (int i = 1; i <= 4; i++) if (deg[i]&1) numOdd++;
    cout << (numOdd==0||numOdd==2?"YES":"NO") << '\n';
}

