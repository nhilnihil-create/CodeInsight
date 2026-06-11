#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int f(int x){
  int cnt=0;
  while(x%2==0){
    cnt++;
    x/=2;
  }
  return cnt;
}

int main(){
  int n;
  cin>>n;
  ll sum=0;
  
  rep(i,n){
    int y;
    cin>>y;
    sum+=f(y);
  }
  cout<<sum<<endl;
  
  return 0; 
}