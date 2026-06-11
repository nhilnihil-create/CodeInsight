#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >>a>>b;
  if(a%b==0){
    cout<<-1<<endl;
    return 0;
  }
  for(int i=a;i<=1000000000;i=i+a){
    if(i%b!=0){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}