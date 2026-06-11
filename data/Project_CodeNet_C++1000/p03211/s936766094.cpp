#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int min(-1);
    for (int i = 0; i < s.size() - 2; ++i)
    {
        int tmp = abs((s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + (s[i + 2] - '0') - 753);
        if (min < 0 || tmp < min)
            min = tmp;
    }
    cout << min << endl;
}