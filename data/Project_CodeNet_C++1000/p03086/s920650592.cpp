#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  string s;
  cin>>s;
  int ans=0,tmp=0;
  set<char> st={'A','G','C','T'};
  for (int i = 0; i < s.size(); ++i)
  {
    tmp=0;
    for (int j = i; j < s.size(); ++j)
    {
      if(st.find(s[j])!=st.end())
      {
        tmp++;
      }
      else break;
    }
    ans=max(ans,tmp);
  }
  cout<<ans<<endl;
}