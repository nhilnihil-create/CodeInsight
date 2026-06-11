#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;

int abs(int x){
  if(x<0){
    x=-x;
  }
  return x;
}

int main(){
  int a,b;
  cin>>a>>b;
  if(a>b){
    cout<<a-1<<endl;
  }else{
    cout<<a<<endl;
  }
}
