#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>kane(n);
  for(int i=0;i<n;i++)
    cin >> kane.at(i);
  sort(kane.begin(),kane.end(),greater());
  int ans=kane.at(0)/2;
  for(int i=1;i<n;i++)
    ans+=kane.at(i);
  cout << ans << endl;
  return 0;
}