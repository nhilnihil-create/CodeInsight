#include<bits/stdc++.h>
using namespace std;
long long i,j,n,m,a[3],b,c,d,k;
string s,x,y;
int main()
{
  cin>>a[0]>>a[1]>>a[2]>>k;
  sort(a,a+3);
  cout<<a[0]+a[1]+a[2]*pow(2,k);
}