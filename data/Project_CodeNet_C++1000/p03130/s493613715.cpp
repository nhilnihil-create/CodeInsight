#include<bits/stdc++.h>
using namespace std;

int main(){
 string n;

  int r,b,c;

  r=0;
  b=0;
  vector<int>a(5);
  for(int i=0;i<6;i++){
    cin>>r;
    a[r]++;
  }
    for(int i=1;i<5;i++){
b=max(b,a[i]);
  }
  if(b!=3){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}
