#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,X;
  cin >> N >> X;
  
  int min;
  
  cin >> min;
  
  X -= min;
  
  for(int i=1;i<N;i++){
    int g;
    cin >> g;
    X -= g;
    if(min>g){
      min=g;
    }
  }
  
  cout << X/min + N << endl;
}
