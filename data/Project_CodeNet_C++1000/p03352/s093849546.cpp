#include<vector>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a;
  for(int i=1;i<50;++i){
    for(int j=2;j<50;++j){
      a.push_back(pow(i,j));
    }
  }
  sort(a.begin(),a.end());
  for(int i=0;i<a.size();++i){
    if(a[i]>n){
      cout<<a[i-1]<<endl;
      return 0;
    }
  }
}