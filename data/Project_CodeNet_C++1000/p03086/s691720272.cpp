#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = s.length();
    int ans = 0;
    for(int i = 0; i < l; i++)
    {
        if(s[i] != 'A' && s[i] != 'T' && s[i] != 'G' && s[i] != 'C') continue;
        int j = i;
        while(1)
        {
            if(i+1 >= l) break;
            if(s[i+1] != 'A' && s[i+1] != 'T' && s[i+1] != 'G' && s[i+1] != 'C') break;
            i++;
        }
        ans = max(ans,i-j+1);
        i++;
    }
    cout << ans << endl;
}