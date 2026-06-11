#include <bits/stdc++.h>
using namespace std; 
int main(){
  int n,t;
  cin >> n >> t;
  vector<pair<int,int>> vec(n);
  int i;
  for(i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    vec.at(i)=make_pair(a,b);
  }
  string s="TLE";
  sort(vec.begin(),vec.end());
  for(i=0;i<n;i++){
    if(vec.at(i).second<=t){
      cout << vec.at(i).first;
      break;
    }
  }
  if(i==n){
    cout << s;
  }
}
  
