#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n,a,s;
   cin>>n>>a;

   s=n%500;
   if(s<=a)
    cout<<"Yes";
    else cout<<"No";
   return 0;
   }