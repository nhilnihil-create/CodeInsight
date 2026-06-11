#include <bits/stdc++.h>
using namespace std; 
#define int int64_t
#define itn int
#define fi first
#define se second
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,c;
  vector<int> a,b;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>c;
    b.push_back(c);
  }
  for(int i=0;i<n;i++){
    for(int j=b.size()-1;j>=0;j--){
      if(b[j]==j+1){
	a.push_back(b[j]);
	b.erase(b.begin()+j);
	break;
      }
    }
  }
  if(b.size()!=0) cout<<-1<<"\n";
  else{
    for(int i=a.size()-1;i>=0;i--){
      cout<<a[i]<<"\n";
    }
  }
  return 0;
}
      
