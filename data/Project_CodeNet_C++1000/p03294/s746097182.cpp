#include<bits/stdc++.h>
using namespace std;
int main(void)
{
  int n;cin >> n;
  int ans = -n;
  for(int i=0;i<n;i++) {
    int a;cin>>a;ans+=a;
  }
  cout << ans<<endl;
}