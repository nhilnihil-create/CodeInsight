#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int size = S.size();
  string ans = "AC";
  int count=0;
  
  if(S.at(0)!='A')ans = "WA";
  for(int i=2;i<size-1; i++){
    if(S.at(i)=='C')count ++;
  }
  if(count != 1)ans= "WA";

  count = 0;
  for(int i=0; i<size; i++){
    if(S.at(i)>'Z')count++;
  }
  if(count != size-2)ans = "WA";
  
  cout << ans << endl;
}