#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int MAXN = 0;

int c[3];
int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        c[s[i]- 'a']++;
    }

    sort(c, c + 3);

    if (c[2] - c[0] <= 1)
        cout << "YES";
    else
        cout << "NO";
	return 0;
}

