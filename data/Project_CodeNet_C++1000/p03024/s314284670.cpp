#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
   
      string s;
       cin>>s;
  
      int i,cnt=0;
       
      for(i=0;i<s.length();++i)
      {
          if(s[i]=='o')
              cnt++;
      }
  
      if(cnt+(15-s.length())>=8)
          printf("YES");
  
      else
         printf("NO");
      
    	return 0;
} 