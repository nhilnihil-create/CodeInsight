
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
#define SortAsc(c) std::sort(c.begin(), c.end())
#define SortDesc(c) std::sort(c.rbegin(), c.rend())
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int main()
{
    string s;
    cin >> s;
    int maxLen = 0;
    int currentLen = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c == 'A' || c == 'C' || c == 'G' || c == 'T')
        {
            currentLen++;
        }
        else
        {
            currentLen = 0;
        }

        if (currentLen > maxLen)
        {
            maxLen = currentLen;
        }
    }

    cout << maxLen << endl;
}