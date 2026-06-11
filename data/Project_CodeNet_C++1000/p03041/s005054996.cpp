#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  string s;
  cin>>n>>k>>s;
  for(int i=0;i<n;i++){
    if(i+1==k) cout<<(char)(s.at(i)-'A'+'a');
    else cout<<s.at(i);
  }
  cout<<endl;
}