#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  string a,b,c;
  cin>>a>>b>>c;
  
  int ans=0;
  
  for(int i=0;i<n;i++){
  		set <char> s;
    s.insert(a[i]);
    s.insert(b[i]);
    s.insert(c[i]);
    ans+=(s.size()-1);
  }
  
  cout<<ans;
	return 0;
}