    #include<bits/stdc++.h>
    #define mp make_pair
    #define f first
    #define s second
    using namespace std;
    int n,krawedzie,akt,pot,nieumiemy,last;
    vector<pair<int,int> >g[25];
    int main()
    {
    ios_base::sync_with_stdio(0);
    cin>>n;
    n--;
    for(int i=1;i<=19;i++)g[i].push_back(mp(i+1,0));
    krawedzie+=19;
    akt=1;
    pot=1;
    while(2*pot-1<=n)
        {
        g[akt].push_back(mp(akt+1,pot));
        krawedzie++;
        pot*=2;
        akt++;
        }
    pot/=2;
    akt--;
    nieumiemy=pot*2;
    last=n;
    while(pot)
        {
        if(pot<=last-nieumiemy+1)
            {
            g[akt].push_back(mp(20,last-pot+1));
            krawedzie++;
            last-=pot;
            }
        pot/=2;
        akt--;
        }
    cout<<20<<' '<<krawedzie<<'\n';
    for(int i=1;i<=20;i++)
        {
        for(int j=0;j<g[i].size();j++)
            {
            cout<<i<<' '<<g[i][j].f<<' '<<g[i][j].s<<'\n';
            }
        }
    }
     
