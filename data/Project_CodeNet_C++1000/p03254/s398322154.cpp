#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,x;
  cin>>N>>x;
  
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  
  sort(vec.begin(),vec.end());
  
  int sum=0;
  for(int i=0;i<N;i++){
    if(x>=vec.at(i)){
      sum+=1;
      x-=vec.at(i);
    }
  }
  if(sum==N&&x>0) cout<<N-1<<endl;
  else cout<<sum<<endl;
}
  