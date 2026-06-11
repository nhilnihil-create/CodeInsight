#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,t;
  cin >> n >> t;
  int c[n],s[n];
  int m=99999;
  for(int i=0;i<n;i++){
    cin >> c[i] >> s[i];
    if(s[i]<=t){
      if(m>c[i])m=c[i];
    }
  }
  if(m==99999)cout << "TLE";
  else cout << m;
}