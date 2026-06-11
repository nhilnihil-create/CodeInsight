#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  string check="ACGT";

  int cnt=0;
  int max=-1;
  for(int i=0;i<s.size();i++){
    int flg=0;
    for(int j=0;j<4;j++){
      if(check.at(j) == s.at(i))flg=1;
    }
    if(flg==1){
      cnt++;
      if(i==s.size()-1 && max<cnt)max=cnt;
    }else {
      if(max<cnt)max=cnt;
      cnt=0;
    }
  }
  cout << max << endl;
  return 0;
}