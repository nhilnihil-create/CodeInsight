#include<bits/stdc++.h>
using namespace std;

#define fre(i,a,b)  for(int (i)=(a);(i)<=(b);++(i))
#define fer(i,a,b)  for(int (i)=(a);(i)>=(b);--(i))

    string s1,s2;
    int N;
bool check(int step,int li,char a,char b)
{
    int L=1,R=li;
    if(s1[N-1]==a)  L++;
    if(s1[N-1]==b)  R--;
    fer(i,N-2,0)
    {
        if(L>R)   return true;
        if(s2[i]==a)    R=min(R+1,li);
        if(s2[i]==b)    L=max(1,L-1);
        if(s1[i]==a)    L++;
        if(s1[i]==b)    R--;
    }
    if(L>R||step>R||step<L) return true;
    return false;
}
int main()
{
    int H,W,x,y;
    ios::sync_with_stdio(false);
    cin>>H>>W>>N>>x>>y;
    cin>>s1>>s2;
    bool ans=check(y,W,'L','R')||check(x,H,'U','D');
    if(!ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}