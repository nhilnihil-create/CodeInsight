#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    long long int N,i,sum=0;
    int a[20],j=0,k;
    cin>>N;
    i=N;
    while(N!=0)
    {
      a[j]=N%10;
      N=N/10;
      j++;
    }
    for(k=0;k<j;k++)
        sum=sum+a[k];
     if(i%sum==0)
     cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
