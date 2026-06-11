#include<bits/stdc++.h>
using namespace std;
int main()
{
string s;
  cin >> s;
  int i,ans1,ans2;
  ans1=0;
  ans2=0;
  vector<char> t1(s.size()),t2(s.size());
  for(i=0;i<s.size();++i)
  {
  if(i%2==0) {t1.at(i)='0';
              t2.at(i)='1';}
  if(i%2==1) {t1.at(i)='1';
              t2.at(i)='0';}
  }
  
   for(i=0;i<s.size();++i)
  {
  if(t1.at(i)==s.at(i)) ans1++;
  if(t2.at(i)==s.at(i)) ans2++;
  }
  if(ans1>ans2) cout << s.size()-ans1;
  else cout << s.size()-ans2;
return 0;}