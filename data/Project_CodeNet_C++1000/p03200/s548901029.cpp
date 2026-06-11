#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    long long black = 0, answer = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == 'B')
            black++;
        else
            answer += black;
    }

    cout << answer << endl;

    return 0;
}
