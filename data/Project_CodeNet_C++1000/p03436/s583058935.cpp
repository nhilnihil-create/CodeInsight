//Grid Repainting

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll, ll>;
using garph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

vector<string> pictureframe(vector<string> md,char fm){
    int w=md[0].size();
    int h=md.size();
    string s(w+2,fm);
    vector<string>picfm(h+2,s);
    rep(i,1,h+1)rep(j,1,w+1)picfm[i][j]=md[i-1][j-1];
    return picfm;
}

signed main (){
    int h,w;cin>>h>>w;
    vecrep(h,a,string);
    int whi = -1;
    rep(i,0,h)rep(j,0,w)if(a[i][j]=='.')whi++;
    a = pictureframe(a,'#');
    queue<p>q;
    q.push(mp(1,1));
    vector<vector<int>>dist(h+2,vector<int>(w+2,-1));
    dist[1][1]=0;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    while(!q.empty()){
        p t = q.front();
        q.pop();
        rep(i,0,4){
            if(a[t.first+dy[i]][t.second+dx[i]]=='#'||dist[t.first+dy[i]][t.second+dx[i]]!=-1)continue;
            dist[t.first+dy[i]][t.second+dx[i]]=dist[t.first][t.second]+1;
            q.push(mp(t.first+dy[i],t.second+dx[i]));
        }
    }
    int c = dist[h][w];
    if(c==-1)cout<<c<<nnn;
    else cout<<whi-c<<nnn;
    return 0;
}