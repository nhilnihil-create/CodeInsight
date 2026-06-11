#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
  int n,a,b;
  cin>>n>>a>>b;
  cout<<min(a,b)<<" ";
  if(a+b-n<0) cout<<'0'<<endl;
  else cout<<a+b-n<<endl;

}