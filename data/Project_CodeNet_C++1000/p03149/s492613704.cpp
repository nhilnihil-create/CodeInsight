#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    vector<int> N(4);
    for (int i = 0; i < 4; i++) cin >> N[i];
    sort(N.begin(), N.end());
    
    cout << (N[0] == 1 && N[1] == 4 && N[2] == 7 && N[3] == 9 ? "YES" : "NO") << endl;
}
