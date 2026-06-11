#include<bits/stdc++.h>
using namespace std;

int main()
{
int A,B;scanf("%d %d",&A,&B);
string S;cin>>S;bool ans=true;
if(S.size()!=A+B+1)ans=false;
for(int i=0;i<A;i++)
{
  if(S[i]-'0'>9||S[i]-'0'<0)ans=false;
}
if(S[A]!='-')ans=false;
for(int i=0;i<B;i++)
{
  if(S[i+A+1]-'0'>9||S[i+A+1]-'0'<0)ans=false;
}
if(ans)printf("Yes\n");
else printf("No\n");
}