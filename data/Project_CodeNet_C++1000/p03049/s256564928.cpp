#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int nab=0,nea=0,nfb=0,eafb=0;
  for(int i=0;i<n;i++) {
    string s;
    cin >> s;
    if(*s.begin()=='B'&&s[s.size()-1]!='A') nfb++;
    if(*s.begin()!='B'&&s[s.size()-1]=='A') nea++;
    if(*s.begin()=='B'&&s[s.size()-1]=='A') eafb++;
    for(int j=0;j<s.size()-1;j++) {
      if(s.substr(j,2)=="AB") nab++;
    }
  }
  int temp;
  if(nea+nfb==0) {
    temp=max(eafb-1,0);
  }
  else {
    temp=eafb+min(nea,nfb);
  }
  cout << nab + temp << endl;
}
