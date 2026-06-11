#include <bits/stdc++.h>

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
int n,s;
 cin>>n;
vector<int> v(n,0);
for(int i=0;i<n;i++)
cin>>v[i];
s=0;
for (auto i = 0; i < n-1; i++)
{
  if (v[i]==v[i+1]){
   s++;
   i++;
  }
}
cout<<s;
  return 0;
}