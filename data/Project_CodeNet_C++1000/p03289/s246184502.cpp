#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  bool frg = true;
  cin >> s;
  if(s[0] != char(65)){frg = false;}
  int cnt = 0;
  int point = -1;
  //bool check = true;
  for (int i=1;i<s.size(); ++i){
    if(s[i] == char(67)){cnt++;point = i;}
    else if((int)s[i] <= 90){frg = false;}
  }
  if(cnt != 1 || point <=1 || point >= s.size()-1){frg = false;}
  if(frg){
    cout << "AC" << endl;
  }else{
    cout << "WA" << endl;
  }
}
