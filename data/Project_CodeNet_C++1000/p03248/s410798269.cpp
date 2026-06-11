#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,rt=1;
char s[N];
vector<pair<int,int> >v;
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    if(s[n]=='1'||s[1]=='0'||s[n-1]=='0'){printf("-1\n");return 0;}
    int l=1,r=n-1;
    while(l<=r)
        if(s[l++]!=s[r--]){printf("-1\n");return 0;}
    v.push_back({1,2});
    rt=2;
    for(int i=3;i<=n;i++)
    {
        v.push_back({rt,i});
        if(s[i-1]=='1') rt=i;
    }
    for(int i=0;i<v.size();i++)
        printf("%d %d\n",v[i].first,v[i].second);
}
