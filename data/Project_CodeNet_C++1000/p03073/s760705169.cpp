#include <iostream>
#include<bits/stdc++.h>
#include <cstring>
using namespace std;

int main()
{
  int i, a = 0, b= 0 ;
  string s;
  cin >> s;
  int l= s.size();
 
  
   for(i = 0; i < l; i+=2)
    {
     if(s[i]!= '0') a++;
    }

   for(i = 1; i < l; i+=2)
    {
     if(s[i]!= '1') b++;
    }

   int ans = a+b;
   if(ans <= l/2) cout << ans;
   else cout << l- ans;
}