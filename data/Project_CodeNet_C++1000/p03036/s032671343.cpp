#include<bits/stdc++.h>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
  int r; int d; int z; cin>>r>>d>>z;
  for(int i=0; i<10; i++){
    cout<<r*z-d<<endl;
    z=r*z-d;
  }
}