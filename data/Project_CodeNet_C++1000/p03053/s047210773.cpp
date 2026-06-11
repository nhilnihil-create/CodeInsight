//Darker and Darker

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define YN(flag) (flag?"Yes":"No")
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int h,w;cin>>h>>w;
    vecrep(h,a,string);
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};

    queue<P>q;
    vector<vector<int>>dist(h,vector<int>(w,-1));

    rep(i,0,h)rep(j,0,w){
        if(a[i][j]=='#'){
            q.push(mp(i,j));
            dist[i][j]=0;
        }
    }

    while(!q.empty()){
        P t = q.front();
        q.pop();
        rep(i,0,4){
            if(t.first+dy[i]<0||t.first+dy[i]>=h||t.second+dx[i]<0||t.second+dx[i]>=w)continue;
            if(a[t.first+dy[i]][t.second+dx[i]]=='#'||dist[t.first+dy[i]][t.second+dx[i]]!=-1)continue;
            dist[t.first+dy[i]][t.second+dx[i]]=dist[t.first][t.second]+1;
            q.push(mp(t.first+dy[i],t.second+dx[i]));
        }
    }

    int ans=0;
    rep(i,0,h)rep(j,0,w){
        ans=max(ans,dist[i][j]);
    }
    
    cout<<ans<<nnn;
    return 0;
}