#include<bits/stdc++.h>
using namespace std;
int main(){
  int S,n,s;
  cin>>S;
  n=S%100;
  s=(S-n)/100;
  if(0<n&&n<=12&&0<s&&s<=12)cout<<"AMBIGUOUS"<<endl;
  else if(0<s&&s<=12) cout<<"MMYY"<<endl;
  else if(0<n&&n<=12) cout<<"YYMM"<<endl;
  else cout<<"NA"<<endl;
}
  
  
  