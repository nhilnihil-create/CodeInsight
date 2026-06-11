#include<bits/stdc++.h>
using namespace std;
#define lc "\n"
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define c(a,n) for(int i = 0; i < n; i++) cin >> a[i];
#define ffor(n) for(int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<float> vf;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<string,int> msi;
typedef map<int,int> mii;
typedef unordered_map<string,int> umsi;

 
 
int32_t main()
{
    fast_io;
    int n,m;
    cin>>n>>m;
    vii g(n+1);
    int x,y;
    vi lgp(n+1,0);
    vi ind(n+1,0);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        g[x].push_back(y);
        ind[y]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
    if(!ind[i])q.push(i);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(auto j:g[t])
        {
            lgp[j]=max(lgp[j],lgp[t]+1);
            ind[j]--;
            if(!ind[j])q.push(j);
        }
    }
    int ans=*max_element(lgp.begin(),lgp.end());
    cout<<ans;
    return 0;
}