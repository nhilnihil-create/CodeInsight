#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,sumR=0,sumB=0;
  cin>>N;
  string s;
  cin>>s;
  for(int i=0;i<N;i++){
    if(s[i]=='R') sumR++;
    else sumB++;    
  }
  if(sumR>sumB) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

}