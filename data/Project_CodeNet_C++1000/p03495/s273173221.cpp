#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,k,b,ans;cin>>n>>k;
  map<int,int> a;
  ans=0;
  for(int i=0;i<n;i++){
  	cin>>b;
    if(a.count(b)){
    	a.at(b)++;
    }else{
    	a[b]=1;
    }
  }
  if(a.size()<=k){
    cout<<0<<endl;
  }else{
    vector<int> aa(a.size());
    int i=0;
  	for (auto p : a) {
  		aa.at(i) = p.second;
      	i++;
  	}
    sort(aa.begin(),aa.end());
    for(int j=0;j<a.size()-k;j++){
    	ans+=aa.at(j);
    }
    cout<<ans<<endl;
  }
  
}