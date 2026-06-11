#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int>a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  int ans=0;
  int count=0;
  for(int i=1;i<N;i++){
    if(a[i]==a[i-1]){
      count++;
    }
    else{
      count=0;
    }
    if(count==1){
      count=-1;
      ans++;
    }
  }
  cout << ans << endl;
}