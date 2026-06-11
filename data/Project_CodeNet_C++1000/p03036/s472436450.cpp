#include<bits/stdc++.h>
using namespace std;

int main(){
  int r,d,a;
  cin>>r>>d>>a;
  for(int i=0;i<10;i++){
    a*=r;
    a-=d;
    cout<<a<<endl;
  }
}

  