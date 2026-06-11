#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> c(n - 1), s(n - 1), f(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> c[i] >> s[i] >> f[i];
    }

    for (int i = 0; i < n; i++)
    {
        long long ans = 0;
        for (int j = i; j < n - 1; j++)
        {
            if(ans < s[j])
            {
                ans = s[j] + c[j];
                //cout << s[j] + c[j] << " ";
            }
            else
            {
                if((ans - s[j]) % f[j] == 0)
                {
                    ans += c[j];
                    //cout << c[j] << " ";
                }
                else
                {
                    ans += f[j] - (ans - s[j]) % f[j] + c[j];
                    //cout << f[j] - (ans - s[j]) % f[j] + c[j] << " ";
                }
                
            }
        }
        cout << ans << endl;
    }
}