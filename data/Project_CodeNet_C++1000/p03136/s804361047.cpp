#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec[i];
  }
  sort(vec.begin(),vec.end());
  
  int sum=0;
  for(int i=0;i<N-1;i++){
    sum+=vec[i];
  }
  
  bool res=false;
  
  
  if(sum>vec[N-1]){
    res=true;
  }
  
  if(res){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
