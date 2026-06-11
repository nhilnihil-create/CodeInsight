#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  string s;
  int n,i,a,maxa;
  cin >> s;
  n=s.size();
  
  a=0;
  maxa=0;
  for(i=0;i<n;i++){
    if(s.at(i)=='A'||s.at(i)=='C'||s.at(i)=='G'||s.at(i)=='T'){
      a++;
    }else{
      maxa=max(a,maxa);
      a=0;
    }
  }
  
  maxa=max(maxa,a);
  cout << maxa << endl;
}