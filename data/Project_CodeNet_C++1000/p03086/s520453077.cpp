#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

using ll = long long;
using P = pair<int, int>;

int main()
{
    string S;
    cin >> S;
    int maxNum = 0;
    rep(i, S.length())
    {
        int tempMaxNum = 0;
        int j = i;
        while (S[j] == 'A' || S[j] == 'C' || S[j] == 'G' || S[j] == 'T')
        {
            j++;
            tempMaxNum++;
        }
        maxNum = max(maxNum, tempMaxNum);
    }
    cout << maxNum << endl;
    return 0;
}