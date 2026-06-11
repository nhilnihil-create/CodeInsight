#include<bits/stdc++.h>
using namespace std;


int main(){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> num;
  if(s[0]=='0') num.push_back(0);
  for(int i=0;i<n;){
    int ren=i;
    while(ren<n && s[i]==s[ren]) ++ren;
    num.push_back(ren-i);
    i=ren;
  }
  if(s.back()=='0') num.push_back(0);

  vector<int> ruisekiwa((int)num.size()+1,0);
  for(int i=0;i<(int)num.size();i++){
    ruisekiwa[i+1]=ruisekiwa[i]+num[i];
  }
  int ans=0;
  for(int i=0;i<(int)ruisekiwa.size();i+=2){
    int j=i+k*2+1;
    if(j>=(int)ruisekiwa.size()) j=(int)ruisekiwa.size()-1;
    ans=max(ans,ruisekiwa[j]-ruisekiwa[i]);
  }
  cout << ans << endl;
  return 0;
}
