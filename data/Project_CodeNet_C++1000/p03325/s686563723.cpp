#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int ans=0;

int devide(int a){
  int sum=0;
  while(a%2==0){
    a/=2;
    sum++;
  }
  return sum;
}

int main(){
  int n;
  cin >> n;
  int a[n];
  rep(i,n)cin >> a[i];

  rep(i,n)ans+=devide(a[i]);
  cout << ans << endl;
}
