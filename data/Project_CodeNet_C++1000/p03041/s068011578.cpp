#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;
using ll = long long;

int main()
{
    string S;
    int N;
    int K;

    cin >> N;
    cin >> K;
    cin >> S;

    S[K - 1] = tolower(S[K - 1]);

    cout << S << endl;

    return 0;
}
