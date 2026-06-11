#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s1=0,s2=0,s;
    scanf("%d",&n);
    int a[n+1];
    for(int i=0; i<n ; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n, greater<int>());
    for(int i=0; i<n ; i++)
    {
        if(i%2==0)
        {
            s1+=a[i];
        }
        else
        {
            s2+=a[i];
        }
    }
    printf("%d\n",s1-s2);
    return 0;

}
