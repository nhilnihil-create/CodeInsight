#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
   string s;
   cin>>s;
   long long int count=0,ans=0;
   for(long long int i=0;i<s.size();i++)
   {
       if(s[i]=='B')
        count++;
       else
        ans=ans+count;
   }
   cout<<ans<<endl;
}
