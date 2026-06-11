#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,x;
  cin >> n >> x;
  vector<int>kdm(n);
  for(int i=0;i<n;i++)
    cin >> kdm.at(i);
  sort(kdm.begin(),kdm.end());
  int ans=0,c=0;
  while(x>0&&c<n){
    if(x>=kdm.at(c)){
      ans++;
    }
    x-=kdm.at(c);
    c++;
  }
  if(x>0&&c==n)
    ans=max(0,ans-1);
  cout << ans << endl;
  return 0;
}