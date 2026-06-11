#include <bits/stdc++.h>
#include<string>
using namespace std;
 
int main()
{
    int a,b,count=0;
    scanf("%d %d",&a,&b);
    for(int i=a;i<=b;i++)
    {
        string s = to_string(i);
        if(s[0]==s[4] && s[1]==s[3]) count++;
    }
    printf("%d",count);
    return 0;
}