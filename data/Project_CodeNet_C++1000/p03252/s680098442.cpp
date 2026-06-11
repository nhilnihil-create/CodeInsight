#include<bits/stdc++.h>
using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  vector<set<int>>alf(26),alf2(26);
  for(int i=0,l=a.size();i<l;i++){
    alf.at(b.at(i)-'a').insert(a.at(i)-'a');
    alf2.at(a.at(i)-'a').insert(b.at(i)-'a');
  }
  bool ans=true;
  for(int i=0;i<26;i++)if(alf.at(i).size()>1||alf2.at(i).size()>1)ans=false;
  cout << (ans?"Yes":"No") << endl;
  return 0;
}