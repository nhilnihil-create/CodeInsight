#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100000000;

int main()
{
   string s,t;
   s = "AKIHABARA";
   cin >> t;
   int i=0,j=0;
   
   for(i,j;i<s.size();i++)
   {
      if(s[i]==t[j])
      {
         j++;
      }
      else if(s[i]=='A')
      {
         
      }
      else
      {
         cout<<"NO"<<endl;
         return 0;
      }
   }

   if(j==t.size())cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
   return 0;
}