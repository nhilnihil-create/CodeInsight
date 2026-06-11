#include<bits/stdc++.h>
using namespace std;


int main(){
  string s;
  cin >> s;
  int k=s.size();
  int w,l;
  w=0;
  l=0;
  for(int i=0;i<k;++i){
    if(s[i]=='o') w++;
    else l++;
  }
  int n=15-k;
  w+=n;
  
  if(w>=8) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
