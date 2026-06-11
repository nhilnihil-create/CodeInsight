#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t;
  cin>>s>>t;
  map<char,int>sn,tn;
  for(int i=0;i<s.size();i++){
    sn[s[i]]++;
    tn[t[i]]++;
  }
  vector<int>si,ti;
  for(auto p:sn){
    si.push_back(p.second);
  }
  for(auto p:tn){
    ti.push_back(p.second);
  }
  sort(si.begin(),si.end());
  sort(ti.begin(),ti.end());
  if(si==ti)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
