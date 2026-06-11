#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,k,i;
  cin >> n >> k;
  vector<char> p(n);
  
  for(i=0;i<n;++i)
  {
  cin >> p.at(i);
    if(i==k-1) p.at(i)=p.at(i)+'a'-'A';
   cout << p.at(i);
  }


return 0;
}