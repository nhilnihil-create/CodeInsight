#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  int sum=700;
  cin>>s;
  if(s.at(0)=='o') sum+=100;
  if(s.at(1)=='o') sum+=100;
  if(s.at(2)=='o') sum+=100;
  cout<<sum<<endl;
	return 0;
}