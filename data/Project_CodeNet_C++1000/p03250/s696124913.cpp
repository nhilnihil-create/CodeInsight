#include<bits/stdc++.h>
using namespace std;
int main()
{
vector<int> h(3);
  for(int i=0;i<3;++i)
  {
  cin >> h.at(i);
  }  
  sort(h.begin(),h.end());
  cout << h.at(0)+h.at(1)+h.at(2)*10;
return 0;
}