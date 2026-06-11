#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
   string s;
   cin>>s;
   int diff, t=753;
   for (int i = 0; i < s.size() -2 ; i++)
   {
       diff = 753 - (s[i]-'0') * 100 - (s[i+1] - '0')*10 - (s[i+2] - '0');
       t = min(t, abs(diff)); 
   }
   cout<<t;
   

   return 0;
}
