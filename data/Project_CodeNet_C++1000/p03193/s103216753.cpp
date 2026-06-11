#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,e,f,g;
  g=0;
  cin>>a>>b>>c;
  for(int i=0;i<a;i++){
    cin>>e>>f;
    if(e>=b&&f>=c){
      g++;
    }
  }
  cout<<g<<endl;
}