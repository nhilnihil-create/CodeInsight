#include <bits/stdc++.h>
using namespace std;



int main(){
  long long a;
  cin >> a;
  string s;
  int keta = 1;
  long long tmp;
  if(a>0){
    s="1";
    tmp=1;
    while (a>tmp){
      keta +=2;
      s="10"+s;
      tmp +=pow(2,keta-1);
    }
  }
  else if(a<0){
    s="10";
    tmp=-2;
    keta=2;
    while(a<tmp){
      keta += 2;
      tmp -= pow(2,keta-1);
      s="10"+s;
    }
  }
  else{
    cout << 0 << endl;
    return 0;
  }
  long long res=abs(tmp-a);
  
  stringstream ss;
  ss<<bitset<64>(res);
  string sabunretu = ss.str();
  int p = s.size();
  int q = sabunretu.size();
  int r = min(p,q);
  string t = s;
  for (int i=0; i<r; i++){
    if(sabunretu[q-1-i]=='1'){
      if(s.at(p-1-i)=='1') s.at(p-1-i)='0';
      else if(s.at(p-1-i)='0') s.at(p-1-i)='1';
    }
  }
  cout << s << endl;    
}