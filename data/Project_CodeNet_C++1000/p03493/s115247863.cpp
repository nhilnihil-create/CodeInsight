#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  int count=0;
  cin>>s;
  if(s.at(0)=='1') count++;
  if(s.at(1)=='1') count++;
  if(s.at(2)=='1') count++;
  cout<<count<<endl;
	return 0;
}