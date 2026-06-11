#include <bits/stdc++.h>
using namespace std;
int pre[104];
int main()
{
       string s;
       cin>>s;
       int t=0;
       for(int i=0;i<s.size();i++){
        if(s[i]=='o')
            t++;
       }
       cout<<(700+t*100);
    return 0;
   }