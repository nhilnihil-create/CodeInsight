#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,h,w,ans=0;
  cin >> n >> h >> w;
  vector<int> H(n),W(n);
  for(int i=0;i<n;i++)
    cin >> H[i] >> W[i];
  for(int i=0;i<n;i++){
    if(W[i]>=w&&H[i]>=h)
      ans++;
  }
  cout << ans << endl;
}