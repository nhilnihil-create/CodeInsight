#include <bits/stdc++.h>
using namespace std;



int main() {
  int64_t N;
  cin>>N;
  map<int64_t,int64_t> ann;
  for(int i=0;i<N;i++){
    int64_t D;
    cin>>D;
    ann[D]++;
  }
  int64_t M;
  cin>>M;
  map<int64_t,int64_t> mon;
  vector<int64_t> vec(M);
  for(int i=0;i<M;i++){
    cin>>vec.at(i);
  }
  for(int i=0;i<M;i++){
    mon[vec.at(i)]++;
  }
  for(int i=0;i<M;i++){
    int64_t x=vec.at(i);
    if(mon[x]>ann[x]){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
}