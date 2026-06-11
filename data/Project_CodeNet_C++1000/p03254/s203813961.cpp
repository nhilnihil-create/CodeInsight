#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,x;
  cin>>N>>x;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  int i=0;
  for(;i<N;i++){
    x-=a[i];
    if(x<0){
      cout<<i<<endl;
      return 0;
    }
    if(x==0){
      cout<<i+1<<endl;
      return 0;
    }
  }
  if(x==0){
    cout<<i<<endl;
  }
  if(x>0){
    cout<<i-1<<endl;
  }
}