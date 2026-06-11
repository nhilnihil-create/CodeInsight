#include <iostream>

using namespace std;

int main(){
  int n;
  string a,b,c;
  cin>>n>>a>>b>>c;
  int ans=0;
  for(int i=0;i<n;i++)ans+=(1+(a[i]!=b[i])+(b[i]!=c[i])+(c[i]!=a[i]))/2;
  cout<<ans<<"\n";
}