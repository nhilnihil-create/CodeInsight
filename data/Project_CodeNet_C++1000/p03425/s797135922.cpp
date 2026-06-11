#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  vector<string> name(N);
  for(int i=0;i<N;i++) cin>>name.at(i);
  sort(name.begin(),name.end());
  vector<long> count(5,0);
  for(int i=0;i<N;i++){
    //if(i>0 && name.at(i-1)==name.at(i)) continue;
    if(name.at(i).at(0)=='M') count.at(0)++;
    if(name.at(i).at(0)=='A') count.at(1)++;
    if(name.at(i).at(0)=='R') count.at(2)++;
    if(name.at(i).at(0)=='C') count.at(3)++;
    if(name.at(i).at(0)=='H') count.at(4)++;
  }
  long ans=0;
  for(int i=0;i<3;i++){
    for(int j=i+1;j<4;j++){
      for(int k=j+1;k<5;k++){
        ans+=count.at(i)*count.at(j)*count.at(k);
      }
    }
  }
  cout<<ans<<endl;
}