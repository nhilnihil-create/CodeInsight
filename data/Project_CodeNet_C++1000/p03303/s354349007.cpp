#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[10010],a[10010];
    int i,j,k,l,w;

    cin>>s;
    cin>>w;

    l=strlen(s);

    j=0;
    for(i=0;i<l;i+=w)
    {
        a[j++]=s[i];
    }
    a[j]='\0';

    printf("%s",a);
}
