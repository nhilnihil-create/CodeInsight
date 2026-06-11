   #include<bits/stdc++.h>
    using namespace std;

    #define ll long long
    #define ff first
    #define ss second
    #define pb push_back
    #define vll vector<ll>
    #define mll map<ll,ll>
    #define MOD 1000000007
    #define pll pair<ll,ll>
constexpr ll INF = 1999999999999999997; 
    #define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
    int main() {
        fastio;

        int n,m;
        cin>>n>>m;
        vector<int>v[m];
        for(int i=0;i<m;i++)
        {
           int k;
           cin>>k;
           while(k--)
           { int x;
            cin>>x;
            x--;
            v[i].pb(x);
           }
        }
        int p[m];
        
        for(int i=0;i<m;i++)
        {
            cin>>p[i];
        }
     int ans=0;
        for(int i=0;i<=pow(2,n)-1;i++)
        {   int f=0;
            for(int j=0;j<m;j++)
            {   int c=0;
                int l=(int)v[j].size();
                for(int k=0;k<l;k++)
                {
                   if((1<<v[j][k])&i)
                    c++;
                }
                 if(p[j]!=c%2)
                  {
                    f=1;
                    break;
                  }
            }
            if(!f)
                ans++;

        }
        cout<<ans<<endl;
    }