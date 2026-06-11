#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int c=b-a;
  int x=0;
  for(int i=1;i<c;i++){
    x+=i;
  }
  cout<<x-a<<endl;
}