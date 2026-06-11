#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  int iti;
  rep(i,n){
    cin >> a.at(i);
    if(a.at(i)==1){
      iti=i+1;
    }
  }
  int ans=0,sum=0;
  while(sum+1<iti){
    sum+=k-1;
    ans++;
  }
  int sum1=0;
  while(max(sum+1,iti)+sum1<n){
    sum1+=k-1;
    ans++;
  }
  cout << ans;
}
      