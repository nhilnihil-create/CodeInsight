#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i;
  cin >> n;
  
vector<long int> b(n),c(n);
  for(i=0;i<n;++i)
  {
  cin >> b.at(i);
  c.at(i)=b.at(i);
  }
  
  sort(c.begin(),c.end());
  
  for(i=0;i<n;++i)
  {
   if(c.at(n/2-1)==c.at(n/2)) cout << c.at(n/2) << endl;
   else{
   if(b.at(i)<=c.at(n/2-1)) cout << c.at(n/2) << endl;
   else cout << c.at(n/2-1) << endl;
   }
  }
  
return 0;
}