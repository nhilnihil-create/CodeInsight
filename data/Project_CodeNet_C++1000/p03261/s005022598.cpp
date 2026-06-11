#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,l,i;
  cin>>n;
  vector<string> w(n);
  for(i=0;i<n;i++) cin>>w.at(i);
  for(i=1;i<n;i++){
    l=w.at(i-1).length();
    if(w.at(i-1).at(l-1)!=w.at(i).at(0)) break;
  }
  if(i<n) cout<<"No"<<endl;
  else{
    sort(w.begin(),w.end());
    for(i=1;i<n;i++) if(w.at(i-1)==w.at(i)) break;
    if(i<n) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
  }
}