#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
    int a,b,k;
    cin>>a>>b>>k;
    int i;
    int c[500];
    int j=0;
    for(i=1;i<=max(a,b);i++)
    {
        if(a%i==0&&b%i==0)
        {
            //cout<<i<<" ";
            c[j]=i;
            j++;
        }
    }
    sort(c,c+j,cmp);
    cout<<c[k-1];
}
