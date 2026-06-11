#include<bits/stdc++.h>

#define rep(i,start,n) for(int i=start;i<(int)(n);i++)
#define rrep(i,n,end) for(int i=n-1;i>=end;i--)
#define each(it,v) for(auto it : v)
#define all(v) (v).begin(),(v).end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using vpii = vector<Pii>;
using vpll = vector<Pll>;

const ll mod=1e9+7;
const int intINF=INT_MAX;
const ll  longINF=LONG_LONG_MAX;

int ans[200200];
int cnt[200200];

main()
{
        int N,C; cin>>N>>C;
        vector<vi> v;
        int s,t,c;
        rep(i,0,N)
        {
                cin>>s>>t>>c;
                v.push_back({s,t,c});
        }
        int k=200020;
        rep(i,0,C)
        {
                rep(j,0,k)cnt[j]=0;
                rep(j,0,N)
                {
                        if(v[j][2]!=i+1)continue;

                        cnt[v[j][0]*2-1]++;
                        cnt[v[j][1]*2+1]--;
                }
                rep(j,1,k)cnt[j]+=cnt[j-1];
                rep(j,0,k)ans[j]+=cnt[j]>0;
                //rep(j,0,k)cout<<cnt[j]<<" ";
                //cout<<endl;
        }
        int x=0;
        rep(i,0,k)x=max(x,ans[i]);
        cout<<x<<endl;
}
