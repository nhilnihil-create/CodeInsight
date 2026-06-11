#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,Y;
  cin>>N>>Y;
  
  int a1=-1;
  int a2=-1;
  int a3=-1;
  
  for(int x=0;x<=Y/10000;x++){
    for(int y=0;y<=Y/5000;y++){
      if(10000*x+5000*y+1000*(N-x-y)==Y&&N>=x+y){
        a1=x;
        a2=y;
        a3=N-x-y;
      }
    }
  }
  
  cout<<a1<<" "<<a2<<" "<<a3<<endl;
}