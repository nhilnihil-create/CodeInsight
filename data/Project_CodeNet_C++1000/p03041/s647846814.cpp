#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    S[K-1] = 'a' + (S[K-1] - 'A');
    cout << S << endl;

    return 0;
}
