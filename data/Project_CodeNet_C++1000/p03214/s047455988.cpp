#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int sum=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum+=a[i];
  }
  int d=1e9;
  int ans;
  for(int i=0;i<n;i++){
    if(d>abs(sum-a[i]*n)){
      d=abs(sum-a[i]*n);
      ans=i;
    }
  }
  cout << ans << endl;
}