#include<cstdio>
#include<cstring>
using namespace std;

char s[100];

int check()
{
    int n=strlen(s);
    if(n>9) return 0;
    int pre=0,now=0;
    char prec='0';
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A') now++;
        else if(s[i]=='K')
        {
            if(now-pre>1||prec!='0') return 0;
            pre=now;
            prec=s[i];
        }
        else if(s[i]=='I')
        {
            if(now-pre>0||prec!='K') return 0;
            pre=now;
            prec=s[i];
        }
        else if(s[i]=='H')
        {
            if(now-pre>0||prec!='I') return 0;
            pre=now;
            prec=s[i];
        }
        else if(s[i]=='B')
        {
            if(now-pre>1||prec!='H') return 0;
            pre=now;
            prec=s[i];
        }
        else if(s[i]=='R')
        {
            if(now-pre>1||prec!='B') return 0;
            pre=now;
            prec=s[i];
        }
        else return 0;
    }

    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='R')
        {
            if(n-i>2) return 0;
            else break;
        }
        if(i==0) return 0;
    }

    return 1;
}

int main()
{
    scanf("%s",s);
    if(check()) puts("YES");
    else puts("NO");
    return 0;
}
