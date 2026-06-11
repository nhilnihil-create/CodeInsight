#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >>n;
  string a,b,c;
  cin >> a>>b>>c;
  int ans=0;
  for(int i=0;i<n;i++){
    char A,B,C;
    A=a.at(i);
    B=b.at(i);
    C=c.at(i);
    if( A==B&&B==C){
      }
      
    else if(A==B||B==C||C==A ){
       ans++;
      }
    else {
       ans+=2;
    }
  }
  cout <<ans;
}