#include<bits/stdc++.h>
using namespace std;
/*
#ifndef ONLINE_JUDGE
    #define cin f
    #define cout g
    ifstream cin("a.in");
    ofstream cout("a.out");
#endif
*/
int n,m;
char w[1<<18],a[1<<18],b[1<<18];
bool ok(bool jk,int poz)
{
    for(int i=1;i<=m;++i)
    {
        if(a[i]==w[poz])
        {
            if(b[i]=='L')
                poz--;
            else poz++;
        }
        if(jk)
        {
            if(poz==n+1) return 1;
        }
        else
            if(poz==0) return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>(w+1);
    for(int i=1;i<=m;++i) cin>>a[i]>>b[i];
    int st=0;
    for(int step=1<<17;step;step>>=1)
        if(st+step<=n&&ok(0,st+step))
            st+=step;
    int dr=n+1;
    for(int step=1<<17;step;step>>=1)
        if(dr-step>0&&ok(1,dr-step))
            dr-=step;
    ///cout<<st<<' '<<dr<<'\n';
    if(dr>st) cout<<dr-st-1;
    else cout<<0;
    return 0;
}
