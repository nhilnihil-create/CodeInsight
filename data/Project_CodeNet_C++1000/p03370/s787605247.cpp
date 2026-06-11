#include <bits/stdc++.h>
using namespace std;
 

int main() {
  int N,X;
  cin>>N>>X;
  
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=vec.at(i);
  }
  int noko=X-sum;
  cout<<noko/vec.at(0)+N<<endl;
}