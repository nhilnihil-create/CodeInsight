#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  char b;
  cin>>b;
  char ans='0';
  if(b=='A'){
      ans='T';
  }
  else if(b=='T'){
      ans='A';
  }
  else if(b=='C'){
      ans='G';
  }
  else if(b=='G'){
      ans='C';
  }
 
  cout<<ans<<endl;
}