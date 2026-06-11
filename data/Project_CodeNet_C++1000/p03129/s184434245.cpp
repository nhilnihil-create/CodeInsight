#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,k;
  cin>>n>>k;
  if(n%2)
    n++;
  if(2*k<=n)
    cout<<"YES";
  else
    cout<<"NO";
}
  