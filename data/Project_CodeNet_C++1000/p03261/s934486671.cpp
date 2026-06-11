#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  bool ok=true;
  string s;
  char c;
  map<string,int>alr;
  for(int i=0;i<n;i++){
    cin >> s;
    alr[s]++;
    if(alr[s]>1)
      ok=false;
    if(i>0){
      if(s.at(0)!=c)
        ok=false;
    }
    c=s.at(s.size()-1);
  }
  cout << (ok?"Yes":"No") << endl;
  return 0;
}