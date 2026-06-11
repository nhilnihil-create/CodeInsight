#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;
    cin>>s;

    bool ans=s[0]=='A';

    int cnt=0;

    for(int i=1;i<s.size();i++)
    {
        if('a'<=s[i]&&s[i]<='z');
        else
        {
            if(2<=i&&i<=s.size()-2&&cnt==0&&s[i]=='C')
            {
                cnt++;
            }
            else
            {
                ans=false;
                break;
            }            
        }        
    }

    ans&=cnt==1;

    puts(ans?"AC":"WA");

    return 0;
}
