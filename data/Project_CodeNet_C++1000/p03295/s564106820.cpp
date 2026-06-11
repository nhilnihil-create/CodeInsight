#include<bits/stdc++.h>
using namespace std;
int main(){
int N,M;
  cin>>N>>M;
  vector<pair<int,int>>A(M);
  for(int i=0;i<M;i++){
  int a,b;
    cin>>a>>b;
    pair<int,int>p(b,a);
    A.at(i)=p;
  }sort(A.begin(),A.end());
  int ans=0;
  int right=0;
  for(int i=0;i<M;i++){
   int a=A.at(i).second;
    int b=A.at(i).first;
    if(right<a){
      right=b-1;
      ans++;
    }
  }cout<<ans<<endl;
    return 0;
}