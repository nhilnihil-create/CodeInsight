#include<bits/stdc++.h>
using namespace std;

int main()
{
  string S;cin>>S;
  vector<int> a(S.size());
  for(int i=0;i<S.size();i++)a[i]=S[i]-'0';
  int ans=0;
  for(int i=0;i<S.size();i++)
  {
    ans+=abs(a[i]-i%2);
  }
  int mans=0;
  for(int i=0;i<S.size();i++)
  {
    mans+=abs(a[i]-(i+1)%2);
  }
  printf("%d\n",min(ans,mans));
}