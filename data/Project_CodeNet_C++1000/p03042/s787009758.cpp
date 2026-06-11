#include <bits/stdc++.h>
using namespace std;

int main(){
  int S;
  cin>>S;
  if(0<S/100 && S/100<=12)
    if(0<S%100 && S%100<=12)
      cout<<"AMBIGUOUS"<<endl;
    else
      cout<<"MMYY"<<endl;
  else
    if(0<S%100 && S%100<=12)
      cout<<"YYMM"<<endl;
    else
      cout<<"NA"<<endl;
}