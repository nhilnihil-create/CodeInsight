#include<bits/stdc++.h>
using namespace std;
int main(){
int N,K;
  cin>>N>>K;
  vector<int>A={};
  for(int i=0;i<K;i++)
    A.push_back(-1000000000);
  for(int i=0;i<N;i++){
  int x;
    cin>>x;
    A.push_back(x);
  
  }for(int i=0;i<K;i++)
    A.push_back(1000000000);
  auto itr=lower_bound(A.begin(),A.end(),0);
  int k=distance(A.begin(),itr);
  int ans;
  if(*itr!=0){
    ans=min(abs(A.at(k-K)),A.at(k+K-1));
    for(int i=0;i<=K-2;i++){
      int a=A.at(k+i); int b=abs(A.at(k-K+1+i));
      int Min=a+b+min(a,b);
      if(Min<ans)
        ans=Min;
    }cout<<ans<<endl;
}else{
ans=abs(A.at(k-K+1));
    for(int i=0;i<K;i++){
    int a=abs(A.at(k-K+i+1));
      int b=A.at(k+i);
      int Min=a+b+min(a,b);
      if(Min<ans)
        ans=Min;
    } cout<<ans<<endl;

}
   return 0;
}