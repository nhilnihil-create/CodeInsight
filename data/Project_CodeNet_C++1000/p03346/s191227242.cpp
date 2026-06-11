#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  map<int,int> m;
  for(int i=1;i<=n;i++){
    int a; cin>>a;
    m[a]=i;
  }
  long long longest=1,count=1;
  for(int i=1;i<n;i++){
    if(m[i]<m[i+1]){
      count++;
    }else{
      longest=max(longest,count);
      count=1;
    }
  }longest=max(longest,count);
  cout<<n-longest<<endl;
}