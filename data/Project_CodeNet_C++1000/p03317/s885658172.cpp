#include<bits/stdc++.h>
using namespace std;
int main()
{  int n,k;
  cin>>n>>k;
 n--;
 k--;
 int t=n/k;
 if(n%k!=0)
   t++;
 cout<<t;
}