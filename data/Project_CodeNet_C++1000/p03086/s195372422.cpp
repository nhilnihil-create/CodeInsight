#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int len=S.length();
  int ans=0;
  int cnt=0;
  for(int i=0;i<len;i++){
    if(S.at(i)=='A'||S.at(i)=='C'||S.at(i)=='G'||S.at(i)=='T'){
      cnt++;
    }
    else {
      cnt=0;
    }
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
  return 0;
}
