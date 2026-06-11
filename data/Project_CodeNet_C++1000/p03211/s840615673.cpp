#include<bits/stdc++.h>
using namespace std;


int main(){
  string s;
  cin >> s;
  int n=s.size();
  int ans=754;
  for(int i=0;i<n-2;++i){
    int cal;
    cal=(s[i]-'0')*100;
    cal+=(s[i+1]-'0')*10;
    cal+=(s[i+2]-'0');
    //cout << cal << endl;
    ans=min(ans,abs(cal-753));
  }
  cout << ans << endl;
  return 0;
}
