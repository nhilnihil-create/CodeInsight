#include<iostream>
using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int ans = (a-b+1)*(a-c+1);
  cout<<ans<<endl;
}