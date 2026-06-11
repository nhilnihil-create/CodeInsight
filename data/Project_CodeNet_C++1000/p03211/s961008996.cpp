#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin >> S;
    int minX = 1000;
    for (int i = 0; i < S.size() - 2; i++)
    {
        int X = (S[i] - '0') * 100 + (S[i + 1] - '0') * 10 + (S[i + 2] - '0');
        minX = min(minX, abs(753 - X));
    }
    cout << minX << endl;
}