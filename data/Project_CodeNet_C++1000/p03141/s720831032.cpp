#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  int64_t A=0,B=0;
  vector<pair<int64_t,int64_t>> p(N);
  for(int i=0;i<N;i++){
    int64_t a,b;
    cin>>a>>b;
    p.at(i)=make_pair(a+b,a);
  }
  sort(p.begin(),p.end());
  reverse(p.begin(),p.end());
  for(int i=0;i<N;i++){
    int64_t x,y;
    tie(x,y)=p.at(i);
  if(i%2==0){
    A+=y;
  }
    else{
      B+=x-y;
    }
  }
  cout<<A-B<<endl;
}