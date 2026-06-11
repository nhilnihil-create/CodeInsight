#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
    cin>>a>>b>>c;
    if(a>b){printf("0\n");}
    else
    {
       if(a*c<b)
       {
           printf("%d\n",c);
       }
       else
       {
           printf("%d\n",(b/a));
       }
    }
    return 0;
}
