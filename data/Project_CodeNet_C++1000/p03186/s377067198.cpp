#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main(){
  long int a,b,c; cin>>a>>b>>c;
  long int gedoku = a+b;
  long int yummy = b+c;
  long int r;
  if(gedoku>=c){
    r = yummy;
  }else{
    r = b + gedoku + 1;
  }
  cout << r << "\n";
}