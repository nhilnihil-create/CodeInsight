#include<bits/stdc++.h>
using namespace std;
int main(){
  string A;
  cin>>A;
  if(A.at(0)=='1'){A.at(0)='9';}
  else{A.at(0)='1';}
  if(A.at(1)=='1'){A.at(1)='9';}
  else{A.at(1)='1';}
  if(A.at(2)=='1'){A.at(2)='9';}
  else{A.at(2)='1';}
  cout<<A<<endl;
}
