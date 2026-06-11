#include<bits/stdc++.h>
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
pair<int,int> s[MN+5],S[MN+5];
int n,pos;long long ans1=0,ans2=0;
int Calc(pair<int,int> s,int&p)
{
    int P=p;
    if(p>=s.first&&p<=s.second) return 0;
    else if(p>s.second) return p=s.second,P-s.second;
    else return p=s.first,s.first-P;
}
bool cmp(pair<int,int> a,pair<int,int> b){return a.second<b.second;}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) s[i].first=read(),s[i].second=read(),S[i]=s[i];
    sort(s+1,s+n+1,greater<pair<int,int> >());
    sort(S+1,S+n+1,cmp);
    for(int i=1;i<=n;++i)
    {
        if(i>1&&S[i].second>=s[i-1].first) break;
        ans1+=Calc(S[i],pos);
        if(S[i].second>=s[i].first) break;
        ans1+=Calc(s[i],pos);
    }
    ans1+=max(pos,-pos);pos=0;
    for(int i=1;i<=n;++i)
    {
        if(i>1&&s[i].first<=S[i-1].second) break;
        ans2+=Calc(s[i],pos);
        if(S[i].second>=s[i].first) break;
        ans2+=Calc(S[i],pos);
    }
    ans2+=max(pos,-pos);
    cout<<max(ans1,ans2);
    return 0;
}