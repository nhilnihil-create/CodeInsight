#include<bits/stdc++.h>
using namespace std;

int main()
{
string S;cin>>S;
int ans=1000;
for(int i=0;i<S.size()-2;i++)ans=min(ans,abs(100*(S[i]-'0')+10*(S[i+1]-'0')+S[i+2]-'0'-753));
printf("%d",ans);
}