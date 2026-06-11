#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
#define vv(a,b) vector< vector<int> > v(a,vector<int>(b,0));
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int mod =1e9+7;
const int di[]={-1,0,1,0},dj[]={0,-1,0,1};

int main()
{
    int h,w;
    cin>>h>>w;
    vector< vector<char> > m(h,vector<char>(w));
    queue<P> que;
    vector< vector<int> > depth(h,vector<int>(w,-1));

    rep(i,h)
    {
        rep(j,w)
        {
            cin>>m[i][j];
            if(m[i][j]=='#')
            {
                que.push(P(i,j));
                depth[i][j]=0;
            }
        }
    }
    while(!que.empty())
    {
        P now=que.front();
        que.pop();
        rep(i,4)
        {
            P np=P(now.first+di[i],now.second+dj[i]);
            if(np.first>=0 && np.first<h && np.second>=0 && np.second<w && m[np.first][np.second]=='.')
            {
                m[np.first][np.second]='#';
                que.push(np);
                depth[np.first][np.second]=depth[now.first][now.second]+1;
            }
        }
    }
    int ans=0;
    rep(i,h)rep(j,w)
    {
        ans=max(ans,depth[i][j]);
    }
    cout<<ans;

}