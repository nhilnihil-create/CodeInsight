#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int Left=a+b;
  int Right=c+d;
  if(Left<Right){
    cout<<"Right"<<endl;
  }
  else if (Left==Right){
    cout<<"Balanced"<<endl;
  }
  else{
    cout<<"Left"<<endl;
  }
}
