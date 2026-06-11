#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll i,j,k,n,a=1;
int main()
{
  for(cin>>n,i=n;i>0;i--)for(j=sqrt(i);j>0;j--)if(j*j==i)return cout<<int(i), 0;
}