#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if((b/a)<c)
    cout<<b/a<<endl;
  else
    cout<<c<<endl;
}
