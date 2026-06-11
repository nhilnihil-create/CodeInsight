#include <iostream>
using namespace std;

int main(){
  int n,q;
  string s;
  cin >> n >> q >> s;
  string k;
  k='0'+s+'1';
  char a[q],b[q];
  for(int i=0;i<q;i++){
    cin >> a[i] >> b[i];
  }
  int l_1=-1,r_1=n+2;
  while(r_1-l_1>1){
    int mid=(r_1+l_1)/2;
    int x=mid;
    char c=k.at(x);
    for(int i=0;i<q;i++){
      if(a[i]==c){
        if(b[i]=='L'){
          x--;
          c=k.at(x);
        }
        else{
          x++;
          c=k.at(x);
        }
      }
    }
    if(c=='0'){
      l_1=mid;
    }
    else{
      r_1=mid;
    }
  }
  int l_2=-1,r_2=n+2;
  while(r_2-l_2>1){
    int mid=(r_2+l_2)/2;
    int x=mid;
    char c=k.at(x);
    for(int i=0;i<q;i++){
      if(a[i]==c){
        if(b[i]=='L'){
          x--;
          c=k.at(x);
        }
        else{
          x++;
          c=k.at(x);
        }
      }
    }
    if(c=='1'){
      r_2=mid;
    }
    else{
      l_2=mid;
    }
  }
  cout << r_2-r_1 << endl;
}