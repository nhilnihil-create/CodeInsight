#include<bits/stdc++.h>
using namespace std;
int main(){
  int z;
  cin>>z;
  if(z%4==0) cout<<"Yes"<<endl;
  else if(z%4==1&&z>=21) cout<<"Yes"<<endl;
  else if(z%4==2&&z>=14) cout<<"Yes"<<endl;
  else if(z%4==3&&z>=7) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}