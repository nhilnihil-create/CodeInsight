#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
typedef pair<int,int>pi;
#define ff first
#define ss second
#define inf 1000000000
#define IOS ios_base::sync_with_stdio(0)
#define bitseT(y,pos) (1<<pos)|y
#define bitchecK(y,pos) ((1<<pos)&y)
#define meM(y,a) memset(y,a,sizeof y)
#define sC(a) scanf("%d",&a)
#define alL(a) a.begin(),a.end()
#define prinT(a,sz)  cout<<a[0];for(int i=1;i<sz;i++)cout<<" "<<a[i];cout<<endl
int ara[100004];
int main()
{
    IOS;
    int n;cin>>n;
    int pos=-1,mx=0;
    for(int i=1;i<=n;i++)
    {
        int a;cin>>a;
        ara[i]=a;
        if(mx<abs(a)){
            mx=abs(a);
            pos=i;
        }
    }
    if(pos==-1){
        cout<<0<<endl;
        return 0;
    }
    vector<pi>ans;
    for(int i=1;i<=n;i++)
    {
        if(ara[i]==0||(ara[i]<0&&ara[pos]>0)||(ara[i]>0&&ara[pos]<0))
        {
            ans.pb({pos,i});
            ara[i]+=ara[pos];
        }
    }
//    cout<<"pos = "<<pos<<" "<<ara[pos]<<endl;
//    prinT(ara,n+1);
    if(ara[pos]>0){
        for(int i=1;i<n;i++)
        {
            ara[i+1]+=ara[i];
            ans.pb({i,i+1});
        }
    }
    else if(ara[pos]<0)
    {
        for(int i=n;i>1;i--)
        {
            ans.pb({i,i-1});
            ara[i-1]+=ara[i];
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
//    prinT(ara,n+1);
}



/*
6
4 -8 5 2 -4 3

*/
