#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int ans=s.size();
  for(int i=0;i<2;i++){
    int cnt=0;
    for(int j=0;j<s.size();j++){
      if(j%2==0&&s.at(j)!=(char)(i+'0')){
        cnt++;
      }
      if(j%2==1&&s.at(j)==(char)(i+'0')){
        cnt++;
      }
    }
    ans=min(ans,cnt);
  }
  cout<<ans<<endl;
}
