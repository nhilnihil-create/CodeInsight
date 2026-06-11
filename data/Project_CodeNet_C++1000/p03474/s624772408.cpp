#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a, b;
    string s;
    cin >> a >> b >> s;
    bool flg = false;
    // cout << s[a] << endl;
    if (s[a] == '-')
    {
        int cnt = 0;
        for (int i = 0; i < a + b + 1; i++)
        {
            int num = (int)(s[i] - '0');
            // cout << num << endl;
            if (0 <= num && num <= 9)
            {
                cnt++;
            }
        }
        if (cnt == a + b)
        {
            flg = true;
        }
    }

    if (flg)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}