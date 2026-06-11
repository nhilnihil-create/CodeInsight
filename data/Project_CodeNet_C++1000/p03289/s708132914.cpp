#include<math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define    ll   long long int
#define    py   printf("Yes\n")
#define    pn   printf("No\n")
#define    in   cin>>
using namespace std;

int main()
{
  string s;
  string ans="AC";
  int cnt=0;
  in s;
  if(s[0]!='A')ans="WA";
    for(int i=1;i<s.size();i++)
    {
      if(isupper(s[i]))
      {
        if(i==1||i==s.size()-1||s[i]!='C')
        {
          ans="WA";
        }
        cnt++;
      }
    }
    if(cnt!=1)ans="WA";
    cout<<ans<<endl;
}
