#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  rep(i,n)cin >> a[i];

  int ans=0;
  int tmp=0;
  int len=1;
  rep(i,n){
    if(tmp==a[i]){
      len++;
    }else {
      len=1;
    }
    tmp=a[i];

    if(len%2==0)ans++;
  }
  cout << ans << endl;
}