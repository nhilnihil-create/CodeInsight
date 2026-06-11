#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
  int x,y,z;
  cin>>x>>z>>y;
  vector<int> s(z);
  for(int i=0;i<z;i++)
   cin>>s[i];
   sort(s.begin(),s.end());
   int p=(lower_bound(s.begin(),s.end(),y)-s.begin());
    int q=z-(lower_bound(s.begin(),s.end(),y)-s.begin());
  cout<<min(p,q)<<endl;
}