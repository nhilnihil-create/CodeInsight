#include <bits/stdc++.h>
using namespace std;

int sum(int x){
  int tmp=0;
  while (x>0){
    tmp+=x%10;
    x/=10;
  }
  return tmp;
}
  





int main() {
  int m;
  cin>>m;
  
  cout<<48-m<<endl;
}

  











