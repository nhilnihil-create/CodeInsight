#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = 0;
    int consequenece = 0, ans = 0;
    char ch;
    while (scanf("%c", &ch) != EOF)
    {
        if (ch == 'A' || ch == 'C' || ch == 'G' || ch == 'T')
        {
            consequenece++;
        }
        else
        {
            ans = max(ans, consequenece);
            consequenece = 0;
        }
    }
    cout << ans << endl;
}
