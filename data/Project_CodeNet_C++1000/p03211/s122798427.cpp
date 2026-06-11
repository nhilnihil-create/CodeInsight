#include<bits/stdc++.h>
using namespace std;
int main()
{
string s;
  cin >> s;
  int min,i,temp,k;
  min=753;
  
  for(i=0;i<s.size()-2;++i)
  {
  temp=int(s.at(i)-'0')*100+int(s.at(i+1)-'0')*10+int(s.at(i+2)-'0');
  if(temp<753) k=753-temp;
  else k=temp-753;
  if(k<min) min=k;
  }

   cout << min;
  
return 0;}