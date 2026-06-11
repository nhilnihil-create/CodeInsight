#include <bits/stdc++.h>
using namespace std;
 
int main() {


  string s;
  cin >>s;
int count_0=0;
  int count_1=0;
  for(int i=0;i<s.size();i++){
  if(s[i]=='0')count_0++;
    if(s[i]=='1')count_1++;
  }
  cout<< min(count_0,count_1) * 2<<endl;
}