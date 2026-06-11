#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  string s;
  cin>>n>>q>>s;
  vector<int>sum(n+1,0);
  vector<int>r(q),l(q);
  for(int i=0;i<q;i++){
    cin>>l[i]>>r[i];
  }
  for(int i=1;i<n;i++){
    if(s[i-1]=='A'&&s[i]=='C'){
      sum[i+1]=sum[i]+1;
    }
    else {
      sum[i+1]=sum[i];
    }
  }
  for(int i=0;i<q;i++){
    cout<<sum[r[i]]-sum[l[i]]<<endl;
  }
}
  
  
