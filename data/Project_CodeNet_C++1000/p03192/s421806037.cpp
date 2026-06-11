#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn for(int i=0;i<n;i++)
#define form for(int j=0;j<m;j++)
#define pb push_back
#define s second
#define f first
int main()
{
   string s;
   cin>>s;
   int n=s.size();
   int cnt=0;
   forn
   {
             if(s[i]=='2') cnt++;
   }
   cout<<cnt;
   return 0;
}