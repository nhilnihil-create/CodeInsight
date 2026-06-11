#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  long long n;
  cin >> s;
  n=s.size();
  long long i,c,p;
  p=0;
  c=0;
  i=n-1;
  while(i>=0){
    if(s.at(i)=='A'){
      c=c+p;
      i--;
    }else{
      if(i<=1){
        p=0;
        i--;
      }else{
        if(s.at(i)=='C'&&s.at(i-1)=='B'){
          p++;
          i=i-2;
        }else{
          p=0;
          i--;
        }
      }
    }
  }
  
  cout << c << endl;
}