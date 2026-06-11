#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{

  int a,b,c,k;
  cin>>a>>b>>c>>k;
  cout<< max({a,b,c})*pow(2,k)+(a+b+c-max({a,b,c}))<<endl;
}
