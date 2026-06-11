#include<math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define    ll   long long int
#define    py   printf("Yes\n")
#define    pn   printf("No\n")
#define    in   cin>>
using namespace std;

ll hako[200000];
int main()
{
  int n,m,x,y;
  string ans="War";
  in n>>m>>x>>y;
  int X[n];
  int Y[m];
  rep(i,n){in X[i];}
  rep(i,m){in Y[i];}

  sort(X,X+n,greater<int>());
  sort(Y,Y+m);
  if(max(x,X[0])<min(y,Y[0]))ans="No War";
  cout<<ans<<endl;
}
