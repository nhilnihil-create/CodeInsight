#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n,a,b;
  cin>>n>>a>>b;
  int ans=min(n*a,b);
  cout<<ans<<endl;
}