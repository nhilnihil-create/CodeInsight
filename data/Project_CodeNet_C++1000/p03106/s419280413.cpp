#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,k; cin>>a>>b>>k;
  vector<int> div(200);
  int cnt=1;
  for(int i=min(a,b);i>=1;i--) {
    if(a%i==0&&b%i==0) {
      div[cnt]=i;
      cnt++;
    }
  }
  cout<<div[k]<<endl;
}
