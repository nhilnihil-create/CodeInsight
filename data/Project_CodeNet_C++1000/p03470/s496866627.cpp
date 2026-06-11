#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  set<int> a;
  for(int i=0;i<n;i++){
    int s;
    cin>>s;
    a.insert(s);
  }
 
  int ans=0;
  auto itr=a.begin();
 while(itr!=a.end()){
     ans++;
   itr++;
  }
  cout<<ans<<endl;
  return 0;
}
