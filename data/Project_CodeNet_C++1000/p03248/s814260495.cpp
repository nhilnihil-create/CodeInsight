#include<bits/stdc++.h>
#define int long long
using namespace std;
 

vector<vector<pair<int,int> > >adj;

int loda1[10][10],loda2[10][10];

int parent[100005];
vector<pair<int,int> >temp;

signed main()
{
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   
 
 
#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif    

    string a;
    cin>>a;
    int n=a.length();

    a="#"+a;
    if(a[1]!='1'||a[n]=='1')
    {
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n/2;i++)
    {
        if(a[i]!=a[n-i])
        {
            cout<<-1;
            return 0;
        }
    }

    int x=1;
    parent[x]=1;

    for(int i=2;i<=n;i++)
    {
        if(a[i]=='1')
        {
            temp.push_back({parent[x],i});
            parent[i]=i;
            for(int j=x+1;j<i;j++)
            {
                parent[j]=i;
                temp.push_back({i,j});                
            }
            x=i;
        }        
    }
    for(int i=x+1;i<=n;i++)
    {
        temp.push_back({parent[x],i});
    }
    for(auto i:temp)
        cout<<i.first<<" "<<i.second<<'\n';
    
}