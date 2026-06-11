#include <bits/stdc++.h>
using namespace std;


int main()
{
    string s;
    cin>>s;
    int cnt[3]={0};
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='a')
            cnt[0]++;
        else if(s[i]=='b')
            cnt[1]++;
        else cnt[2]++;
    }
    int ok=1;
    sort(cnt,cnt+3);

    while(1)
    {
        if(cnt[0]&&cnt[1]&&cnt[2])
            cnt[0]--,cnt[1]--,cnt[2]--;
        else if(cnt[1]&&cnt[2])
        {
            if(cnt[2]>1)
                ok=0;
            cnt[1]--,cnt[2]--;
        }
        else if(cnt[2])
        {
            if(cnt[2]>1)
                ok=0;
            cnt[2]--;
        }
        else break;
    }
    cout<<((ok)?"YES\n":"NO\n");
    return 0;
}
