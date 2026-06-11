#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define forn(i,n) for(int i=0;i<(int) n;i++)
#define Forn(i,n) for(int i=1;i<=(int) n;i++)

int main()
{
  int n,i,j;
  cin>>n;
  int a[n];
  int b[n];
  for(i=0;i<n;i++) cin>>a[i];
  for(i=0;i<n;i++) cin>>b[i];
  int N=n;
  int x=0,y=0;
 for(i=0;i<n;i++)
  {

      if(a[i]>b[i])
      {
          x+=a[i];
          y+=b[i];
      }
  }
   cout<<x-y;

}




