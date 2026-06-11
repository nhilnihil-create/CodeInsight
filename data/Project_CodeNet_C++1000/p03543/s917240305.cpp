#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,a,b,c,d;
  
  cin >> N;
  
  a=N/1000;
  b=N/100-10*a;
  c=N/10-100*a-10*b;
  d=N-1000*a-100*b-10*c;
  
  if((a==b && b==c)||(b==c && c==d)){
    cout <<"Yes"<<endl;
  }
  else {
    cout <<"No"<<endl;
  }
}