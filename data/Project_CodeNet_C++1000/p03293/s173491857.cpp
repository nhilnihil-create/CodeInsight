#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int i, i1, i2;
    char x;
    for (i1 = 0; i1 < t.size(); i1++)
    {
        x = t[t.size() - 1];
        for (i = t.size() - 1; i >= 0; i--)
        {
            t[i + 1] = t[i];
        }
        t[0] = x;
        if (t == s)
        {
            cout << "Yes";
            return 0;;
        }
    }
    cout << "No";
    return 0;
}