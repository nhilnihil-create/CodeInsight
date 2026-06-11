#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
    cin >> n >> a >> b;

    string ans = "Draw";
    if(n == 2 && a == 1 && b == 2)
    {
        ans = "Borys";
    }
    else
    {       
        int i;
        for (i = 0; i < n; i++)
        {
            if(a + 1 == b)
            {
                break;
            }
            if(i % 2 == 0)
            {
                a++;
            }
            else
            {
                b--;
            }
        }
        if(i % 2 == 1)
        {
            ans = "Alice";
        }
        else
        {
            ans = "Borys";
        }
    }
    cout << ans << endl;
}
