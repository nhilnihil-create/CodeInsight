#include<math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;


int main () {
  int n;
  cin>>n;
  double x[n],ans=0;
  string y[n];
  for(int i=0;i<n;i++)
  {
    cin>>x[i];
    cin>>y[i];
    if(y[i]=="JPY")ans+=x[i];
    else ans+=(x[i]*380000.0);
  }

  cout<<ans<<endl;
}
