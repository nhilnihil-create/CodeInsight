#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    int k = n;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            int m = max(i + 1, n - (i + 1));
            k = min(k, m);
        }
    }
    cout << k << endl;
    return 0;
}