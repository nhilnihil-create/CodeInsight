#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  scanf("%2d%2d", &a, &b);
  bool am, bm;
  am = 0<a && a<=12;
  bm = 0<b && b<=12;

  if(am && bm){
    cout<<"AMBIGUOUS"<<endl;
  }else if(am && !bm){
    cout<<"MMYY"<<endl;
  }else if(!am && bm){
    cout<<"YYMM"<<endl;
  }else if(!am && !bm){
    cout<<"NA"<<endl;
  }
}