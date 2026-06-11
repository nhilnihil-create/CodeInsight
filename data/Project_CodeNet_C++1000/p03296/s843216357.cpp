#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> data(N);
  for(int i=0;i<N;++i){
    cin>>data.at(i);
  }
  int ans= 0;
  int sum= 0;
  while(sum+1<N){
    if(data.at(sum)==data.at(sum+1)){
      ans++;
      sum+= 2;
    }
    else{
      ++sum;
    }
  }
  cout<<ans<<endl;
}