#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(i=a;i<=n;i++)
#define test(a) cout << "*" << a << endl
int main (){
  int i,j;
  int N,M,X,Y;
  int x[120];
  int y[120];
  int xMax = -9999;
  int yMin = 9999;
  bool peace = false;
  
  cin >> N >> M >> X >> Y;
  
  rep(i,1,N){
    cin >> x[i];
    xMax = max(xMax,x[i]);
  }
    
  rep(i,1,M){
    cin >> y[i];
    yMin = min(yMin,y[i]);
  }
  
  /*rep(i,1,N)
    test(x[i]);
  cout << "*" << endl;
  rep(i,1,M)
    test(y[i]);*/
  
  for(i=xMax+1;i<=yMin;i++){
    if(X<i && i<=Y){
      peace = true;
      break;
    }
  }
    
  
  /*for(i=Y;i>X+1;i--){
    if(xMax<i && i<=yMin){
      peace = true;
      break;
    }
    else{
      peace = false; 
    }
  }*/
  if(peace==true)
    cout << "No War" << endl;
  else if(peace==false)
    cout << "War" << endl;
  
  
}