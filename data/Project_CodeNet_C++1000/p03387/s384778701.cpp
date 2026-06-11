#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  vector<int> a(3);
  for(int &i:a)cin>>i;
  sort(a.begin(),a.end());
  int A=a[0],B=a[1],C=a[2];
  if((C-A)%2==(C-B)%2)cout<<(C*2-A-B)/2<<endl;
  else cout<<(C*2-A-B+3)/2<<endl;
}