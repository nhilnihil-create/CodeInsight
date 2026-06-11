#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 0;
    char s[3];
    for(int i = 0; i < 3; i++)
    {
        cin >> s[i];
        if(s[i] == '1')
            ans++;
    }
    cout << ans << endl;
    return 0;
}
