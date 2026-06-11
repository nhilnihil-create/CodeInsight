#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int N,A[200],B[200],i,j,k,c[200],*n,sum=0;
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
    }
    for(i=0;i<N;i++)
    {
        cin>>B[i];
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<=i;j++)
        {
          sum+=A[j];
        }
        for(k=i;k<N;k++)
            sum+=B[k];
      c[i]=sum;
      sum=0;
    }
    n=max_element(c,c+N);
    cout<<*n;
}
