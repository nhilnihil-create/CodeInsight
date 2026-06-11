#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  int n,h;
  cin>>n>>h;

  vector<pair<int, int> > pairs(n);
  int max_a=0;
  for(int i=0;i<n;i++){
    cin>>pairs.at(i).second>>pairs.at(i).first;
    max_a=max(pairs.at(i).second,max_a);
  }

  sort(pairs.begin(), pairs.end(),greater<>());

  int cnt=0;
  int i=0;
  while(h>0){
    if(i<n && max_a<pairs.at(i).first){
      h-=pairs.at(i).first;
      cnt++;
      i++;
    }else{
      int wk = ceil((double)h/(double)max_a);
      h-=wk*max_a;
      cnt += wk;
    }
  }

  cout<<cnt<<endl;

  return 0;
}