#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
   int i,j,k,n,m; int a[3];
   for(i=0;i<3;i++) cin>>a[i];
   sort(a,a+3);
   int res=abs(a[1]-a[0])+abs(a[2]-a[1]);
   cout<<res;
}
