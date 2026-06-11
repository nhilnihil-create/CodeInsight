#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
int main(){
  int n; cin>>n;
  vector<P> num;
  for(int i=1;i<n;i++){
    if(n%2==1){
      for(int j=i+1;j<=n;j++){
        if(j==n-i) continue;
        num.push_back(P(i,j));
      }
    }else{
      for(int j=i+1;j<=n;j++){
        if(j==n-i+1) continue;
        num.push_back(P(i,j));
      }
    }
  }
  cout<<num.size()<<endl;
  for(int i=0;i<num.size();i++){
    cout<<num[i].first<<' '<<num[i].second<<endl;
  }
}