#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int t = 0;
  cin>>n;
  for(int i=0; i < n; i++){
    char a;
    cin>>a;
    if(a == 'Y'){
      cout<<"Four"<<endl;
      t = 0;
      break;
    }else{
      t++;
    }
  }
  if(t >= 1){
     cout<<"Three"<<endl;
  }
}
