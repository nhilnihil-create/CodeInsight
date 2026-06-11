#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n,k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i,n){
    cin >> h.at(i);
  }
  int ans=1,now=k;
  while(now<n){
    now+=k-1;
    ans++;
  }
  cout<< ans;
}