#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<long> a(4);
  for(int i=0;i<6;i++){
    int x;
    cin>>x;
    a[x-1]++;
  }
  sort(a.begin(),a.end());
  int b[4]={1,1,2,2};
  bool flg=false;
  for(int i=0;i<4;i++){
    if(a[i]!=b[i]) continue;
    if(i==3) flg=true;
  }
  if(flg) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
