#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int k=b/a;
    if(k>=c)
    {
        printf("%d\n",c);
    }
    else printf("%d\n",k);
    return 0;
}
