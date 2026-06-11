#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    string s;

    cin >> n >> s;

    int max = -1;

    for (int i = 1; i < n; i++)
    {
        int cnt = 0;
        vector<bool> ala(26, false);
        vector<bool> alb(26, false);
        // cout << "i:" << i << endl;
        for (int j = 0; j < i; j++)
        {
            // cout << s[j] << ",";
            ala[s[j] - 'a'] = true;
        }
        // cout << endl;
        for (int k = i; k < n; k++)
        {
            // cout << s[k] << ",";
            alb[s[k] - 'a'] = true;
        }
        // cout << endl;
        for (int j = 0; j < 26; j++)
        {
            if (ala[j] && alb[j])
            {
                cnt++;
            }
        }
        // cout << "cnt:" << cnt << endl;
        if (max < cnt)
        {
            max = cnt;
        }
        // cout << endl;
    }
    cout << max << endl;
    return 0;
}
