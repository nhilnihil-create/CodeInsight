#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  
  vector <int> d(N);
  
  for(int i=0;i<N;i++){
    cin >> d.at(i);
  }
  
  for(int i=0;i<N;i++){
    for(int j=i;j<N;j++){
      if(d.at(i)<d.at(j)){
        int t;
        t=d.at(i);
        d.at(i)=d.at(j);
        d.at(j)=t;
      }
    }
  }
  
  int ans=0;
  
  for(int i=1;i<N;i++){
    if(d.at(i)<d.at(i-1))ans++;
  }
  
  cout << ans+1 << endl;
  
}