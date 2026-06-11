#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  int a,b,c,d; cin>>a>>b>>c>>d;
  if(a+b>c+d)cout<<"Left"<<endl;
  else if(a+b<c+d)cout<<"Right"<<endl;
  else cout<<"Balanced"<<endl;
}

