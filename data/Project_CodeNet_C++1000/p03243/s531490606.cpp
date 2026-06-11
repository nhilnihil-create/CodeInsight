#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    for (int i = N; i < 1000; i++)
    {
        string s = to_string(i);
        if (s[0] == s[1] && s[1] == s[2])
        {
            cout << s << endl;
            return 0;
        }
    }
}