#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int n;
  cin>>n;
  int k=-1;
  for(int i=1;i<=n+1;i++)if(i*(i-1)/2==n)k=i;
  if(k==-1)cout<<"No"<<endl;
  else{
    cout<<"Yes"<<endl;
    cout<<k<<endl;
    int p=2*n/k;
    vector<int> v[k];
    int c=1;
    for(int i=0;i<k;i++){
      for(int j=i+1;j<k;j++){
	v[i].push_back(c);
	v[j].push_back(c++);
      }
    }
    for(int i=0;i<k;i++){
      cout<<p;
      for(int x:v[i]){
	cout<<" "<<x;
      }
      cout<<endl;
    }
  }
  return 0;
}