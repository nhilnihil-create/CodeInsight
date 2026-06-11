#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  int max_num=vec.at(0);
  for(int i=1;i<N;i++){
    if(max_num<vec.at(i)){
      max_num=vec.at(i);
    }
  }
  int sum=accumulate(vec.begin(),vec.end(),0);
  if(max_num<sum-max_num)
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;

}
