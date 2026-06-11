#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector <int> b(n);
  for (int i=0;i<n;i++) cin>>b.at(i);
  
  sort(b.begin(),b.end(),greater<int>());
  int temp=0,ans=0;
  for(int i=0;i<n;i++){
    if(temp==b.at(i)) continue;
    temp=b.at(i);
    ans++;
  }
  cout<<ans<<endl;  
}