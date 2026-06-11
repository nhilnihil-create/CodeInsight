#include<bits/stdc++.h>
using namespace std;

int main()
{
int s,count=1;scanf("%d",&s);
set<int> S;S.insert(s);
while(true)
{
if(s%2==0)s/=2;
else s=3*s+1;
count++;
if(S.count(s))break;
else S.insert(s);
}
printf("%d\n",count);
}