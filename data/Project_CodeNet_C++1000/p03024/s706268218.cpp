#include<bits/stdc++.h>
using namespace std;
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin>>s;
  int count=0;
  int n=s.length();
    for(int i=0;i<n;i++){
      if(s[i]=='x') count++;
  }
  cout<<(count<8? "YES":"NO")<<endl;
  return 0;
}
