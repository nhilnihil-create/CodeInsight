#include<bits/stdc++.h>
using namespace std;
int main(){
int N; string S;
  cin>>N>>S;
  int k=0;
  for(int i=0;i<N;i++)
    if(S.at(i)=='.')
      k++;
  int ans=k;
  for(int i=0;i<N;i++){
  if(S.at(i)=='.')
    k--;
    else
      k++;
    if(k<ans)
      ans=k;
 }cout<<ans<<endl;
    return 0;
}