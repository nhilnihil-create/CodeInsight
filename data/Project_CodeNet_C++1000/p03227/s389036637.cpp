#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    string S;
    cin >> S;

    if (S.size() == 3) {
        swap(S[0], S[2]);
    }

    cout << S << endl;
}
