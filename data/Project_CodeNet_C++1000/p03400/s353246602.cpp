#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,d,x;
  cin >> n >> d >> x;
  vector<int>kosu(n);
  for(int i=0;i<n;i++)
    cin >> kosu.at(i);
  int ans=x;
  for(int i=0;i<n;i++){
    ans+=d/kosu.at(i);
    if(double(d)/kosu.at(i)!=d/kosu.at(i))
      ans++;
  }
  cout << ans << endl;
  return 0;
}