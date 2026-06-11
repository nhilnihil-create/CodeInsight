#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  if(c<min(a,b) || c>max(a,b))cout<<"No\n";
  else cout<<"Yes\n";
	return 0;
}
