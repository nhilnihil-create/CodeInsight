#include<bits/stdc++.h>
using namespace std;

int main(){
  int sn,tn,c;
  cin >> sn >> tn >> c;
  vector<int>b(tn);
  for(int i=0;i<tn;i++)
    cin >> b.at(i);
  int ans=0,su,x;
  for(int i=0;i<sn;i++){
    su=0;
    for(int j=0;j<tn;j++){
      cin >> x;
      su+=x*b.at(j);
    }
    if(su+c>0)
      ans++;
  }
  cout << ans << endl;
  return 0;
}