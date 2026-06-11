#include <bits/stdc++.h>
using namespace std;
int main (){
  int N;
  cin>>N;
  vector<int> r(N);
  for(int i=0;i<N;i++){
    cin>>r.at(i);
  }
  sort(r.begin(),r.end());
  for(int i=0;i<N-1;i++){
    if(r.at(i)==r.at(i+1)){
      for(int j=i;j<N-1;j++){
        r.at(j)=r.at(j+1);
      }
      r.pop_back();
      N--;
      i--;
    }
  }
  cout<<r.size()<<endl;
}