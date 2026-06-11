#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b;
  cin>>a>>b;
  int x=b-a;
  int ans=((x*(x-1))/2)-a;
  cout<<ans<<endl;
   return 0;
}