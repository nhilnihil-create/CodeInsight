#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<char> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  sort(v.begin(),v.end());
  if(n%2==0){
    int cent=n/2;
    if(v[cent-1]=='R'&&v[cent]=='R') cout<<"Yes"<<endl;
    else if(v[cent-1]=='R'&&v[cent]=='B') cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  else {
    int cent=n/2;
    if(v[cent]=='R') cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  return 0;
}