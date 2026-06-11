#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>kazu(n);
  for(int i=0;i<n;i++)
    cin >> kazu.at(i);
  bool ok=true;
  int ans=0;
  while(ok){
    for(int i=0;i<n;i++){
      if(kazu.at(i)%2==0)
        kazu.at(i)/=2;
      else
        ok=false;
    }
    if(!ok)
      break;
    ans++;
  }
  cout << ans << endl;
}