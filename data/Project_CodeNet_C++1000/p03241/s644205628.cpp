#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int N,M;cin>>N>>M;
  vector<int> v;
  for(int i=1;i*i<=M;i++)if(M%i==0){
    v.push_back(i);
    if(M/i!=i) v.push_back(M/i);
  }
  sort(v.begin(),v.end());
  int c=*lower_bound(v.begin(),v.end(),N);
  cout<<M/c<<endl;
  return 0;
}