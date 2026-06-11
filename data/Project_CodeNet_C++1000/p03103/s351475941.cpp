#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n,m;
  cin>>n>>m;
  map<int,int> a;//money-cnt
  rep(i,n){
    int A,B;
    cin>>A>>B;
    a[A]+=B;
  }
  ll sum=0;//money
  int cnt=0;
  bool flag=0;
  for(auto x : a){
    while(x.second!=0){
      x.second--;
      cnt++;
      sum+=x.first;
      if(cnt==m){
        flag=1;
        break;
      } 
    }
    if(flag)break;
  }
  cout<<sum<<endl;
}