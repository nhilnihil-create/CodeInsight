#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int s;cin>>s;
  vector<int> vec(1100000);
  int cnt=0;
  while(1){
    cnt++;
      vec[s-1]++;
    if(vec[s-1]==2)break;
    if(s%2==0)s=s/2;
    else s=3*s+1;
  }
  cout<<cnt<<endl;
}
