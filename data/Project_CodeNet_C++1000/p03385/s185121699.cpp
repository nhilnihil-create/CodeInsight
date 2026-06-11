#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >>s;
  bool hantei_a=false;
  bool hantei_b=false;
  bool hantei_c=false;
  for(int i=0;i<3;i++){
    if(s[i]=='a')hantei_a=true;
    if(s[i]=='b')hantei_b=true;
    if(s[i]=='c')hantei_c=true;
  }
  if(hantei_a==true&&hantei_b==true&&hantei_c==true){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}