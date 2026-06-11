#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<string> vec(N);
  for(int i=0;i<N;i++) {
    cin>>vec.at(i);
  }
  string ans="Yes";
  
  for(int i=0;i<N-1;i++) {
    if(vec.at(i)[vec.at(i).size()-1]!=vec.at(i+1)[0]) {
      ans="No";
      break;
    }
  }
  
  sort(vec.begin(),vec.end());
  
  for(int i=0;i<N-1;i++) {
    if(vec.at(i)==vec.at(i+1)){
      ans="No";
      break;
    }
  }
  
  cout<<ans<<endl;
  return 0;
}