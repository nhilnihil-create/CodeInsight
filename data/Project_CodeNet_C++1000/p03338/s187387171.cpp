#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    string x,y;
    int k = 1;
    int cnt = 0;
    for (int j = 0; j < n; j++)
    {
        x = "";
        y = "";
        cnt = 0;
        for (int i = 0; i < k; i++)
        {
            x += s[i];
        }

        for (int i = k; i < n; i++)
        {
            y += s[i];
        }

        for (char c = 'a'; c <= 'z'; c++)
        {
            bool flagx = false, flagy = false;
            for (int i = 0; i < k; i++)
            {
                if(x[i] == c) flagx = true;
            }
            for (int i = 0; i < n-k; i++)
            {
                if(y[i] == c) flagy = true;
            }
            if(flagx && flagy) cnt++;
            
        }  
        if(ans < cnt) ans = cnt;
        k++; 

    }

    cout << ans << endl;
    return 0;
}