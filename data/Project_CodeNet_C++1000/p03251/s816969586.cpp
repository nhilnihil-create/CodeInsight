#include <bits/stdc++.h>
using namespace std; 
int main(){
  int n,m,x,y;
  cin >>n>>m>>x>>y;
  int i;
  int maxi=x,mini=y;
  vector<int> s(n),t(m);
  for(i=0;i<n;i++){
    cin >> s.at(i);
    maxi=max(maxi,s.at(i));
  }
  for(i=0;i<m;i++){
    cin >> t.at(i);
    mini=min(mini,t.at(i));
  }
  if(mini>maxi){
    cout <<"No War";
  }else{
    cout << "War";
    }
}   
	
