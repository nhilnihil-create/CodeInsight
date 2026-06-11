#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin>>s;
  int c=0;
  if (s.substr(0,7)=="keyence") c==1;
  if (s.substr(0,6)=="keyenc" && s.substr(s.size()-1)=="e") c=1;
  if (s.substr(0,5)=="keyen" && s.substr(s.size()-2)=="ce") c=1;
  if (s.substr(0,4)=="keye" && s.substr(s.size()-3)=="nce") c=1;
  if (s.substr(0,3)=="key" && s.substr(s.size()-4)=="ence") c=1;
  if (s.substr(0,2)=="ke" && s.substr(s.size()-5)=="yence") c=1;
  if (s.substr(0,1)=="k" && s.substr(s.size()-6)=="eyence") c=1;
  if (s.substr(s.size()-7)=="keyence") c=1;
  cout<<(c==1 ? "YES" : "NO")<<endl;
}