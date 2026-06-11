#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin >> a.at(i);
  int64_t ans=1;
  for(int i=0;i<n;i++){
    if(a.at(i)%2==0)
      ans*=2;
  }
  ans=pow(3,n)-ans;
  cout << ans << endl;
  return 0;
}