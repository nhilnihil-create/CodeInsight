#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s[100];
    int i, i1;
    int m = 0;
    for(i = 0; i < n; i++)
    {
        cin >> s[i];
        if (i != 0)
        {
            if (s[i][0] != s[i - 1][s[i - 1].size()-1])
            {
                m = 1;
            }
        }
        for (i1 = 0; i1 < i; i1++)
        {
            if (s[i1] == s[i]) {
                m = 1;
            }
        }
    }
    if (m == 0)
        cout << "Yes";
    else
        cout << "No";
    return 0;
    }