#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b,x,y;
  cin >> n >> a >> b;
  if(a<b){
    x = a;
  }else{
    x = b;
  }
  if(a+b-n<0){
    y = 0;
  }else{
    y = a+b-n;
  }
  cout << x << " " << y << endl;
}