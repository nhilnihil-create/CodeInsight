#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d,e,k;
  cin>>a>>b>>c>>d>>e>>k;
  if(e-a>k  ||d-a>k ||c-a>k ||b-a>k){
    cout<<":("<<endl;
  }
  else {
    cout<<"Yay!"<<endl;
  }
}
