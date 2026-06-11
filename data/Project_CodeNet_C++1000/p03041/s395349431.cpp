#include<bits/stdc++.h>
using namespace std;
void PDF(char A[],int k,int n)
{
    int l,i,c,s,t;
    for(i=1;i<=n;i++)
    {
        if(i==k)
        {
            A[i] = A[i]+32;
        }
    }
    for (i=1;i<=n;i++)
    {
        cout<<A[i];
    }
}
int main()
{
    int n,i,k,j,l;
    cin >> n >>k;
    char A[100];
    for(i=1;i<=n;i++)
    {
        cin>> A[i];
    }
    PDF(A,k,n);
    return 0;
}
