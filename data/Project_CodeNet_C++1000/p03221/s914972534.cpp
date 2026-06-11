#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  
  set<tuple<int,int,int>> s;
  int a,b;
  rep(i,m){
    cin>>a>>b;
    s.insert({a,b,i});
  }
  
  vector<int> A(m),B(m);
  int tmp=-1,cnt=0;
  for(auto x:s){
    if(tmp!=get<0>(x)){
      tmp=get<0>(x);
      cnt=1;
    }
    else cnt++;
    A[get<2>(x)]=get<0>(x);
    B[get<2>(x)]=cnt;
  }
  
  rep(i,m){
    cout<<setfill('0')<<right<<setw(6)<<A[i];
    cout<<setfill('0')<<right<<setw(6)<<B[i]<<endl;
  }
  
  return 0;
}