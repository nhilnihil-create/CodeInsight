#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  b=0;
  c=0;
  cin>>a;
  char d;
  for(int i=0;i<a;i++){
    cin>>d;
    if(d=='R'){
      b++;
    }
    else {
      c++;
    }
  }
  if(b>c){
    cout<<"Yes"<<endl;
  }
  else {
    cout<<"No"<<endl;
  }
}