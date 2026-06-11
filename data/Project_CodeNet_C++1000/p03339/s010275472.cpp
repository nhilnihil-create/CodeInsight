#include<bits/stdc++.h>
using namespace std;
int main(){
   int N;
  string s;
  cin>>N>>s;
  vector<char>C(N);
  for(int i=0;i<N;i++)
  cin>>s.at(i);
  int sum=0;
  for(int i=1;i<N;i++)
    if(s.at(i)=='E')
      sum++;
  int ans=sum;
  for(int i=1;i<N;i++){
  if(s.at(i)=='E')
    sum--;
    if(s.at(i-1)=='W')
      sum++;
    if(sum<=ans)
      ans=sum;
  } cout<<ans<<endl;
   
  return 0;
}