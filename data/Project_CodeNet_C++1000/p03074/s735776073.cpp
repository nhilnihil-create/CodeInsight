#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[100008];
    queue<int>q;
    int n,k=0,c=0,x=0;
    scanf("%d%d",&n,&k);
    scanf("%s",a);
    int b=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='0')
        {
            while(a[i]!='1' && i<n){i++;b++;}
            q.push(b);
            b=0;
            i--;
        }
        else b++;
    }

    for(int i=0;i<n;i++)
    {
        if(a[i])
        if(k>0 && a[i]=='0')
        {
            while(a[i]!='1' && i<n)
            {
                i++;c++;
            }
            k--;i--;
        }
        else if(k==0 && a[i]=='0')
        {
            //cout<<c<<endl;
            if(c>x)x=c;
            c-=q.front();
            q.pop();
            //cout<<c<<endl;
            while(a[i]!='1' && i<n)
            {
                i++;
                c++;
            }
            i--;
        }
        else c++;
    }
    //cout<<c<<endl;
    if(c>x)x=c;
    printf("%d",x);
    return 0;
}
