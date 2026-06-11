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
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(abs(a-c)<=d||(abs(a-b)<=d&&abs(b-c)<=d)){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
