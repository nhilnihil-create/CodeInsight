#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    int N,K;cin>>N>>K;
    vector<ll> vx(N),vy(N);
    vector<ll> vx2(N),vy2(N);
    REP(i,N){cin>>vx[i]>>vy[i];vx2[i]=vx[i];vy2[i]=vy[i];}
    sort(all(vx2));sort(all(vy2));
    vector<vector<int> > plane(N+1,vector<int>(N+1,0));
    vector<int> wx(N),wy(N);
    REP(i,N){
        wx[i]=(int)(lower_bound(all(vx2),vx[i])-vx2.begin())+1;
        wy[i]=(int)(lower_bound(all(vy2),vy[i])-vy2.begin())+1;
    }
    REP(i,N){
        plane[wx[i]][wy[i]]=1;
    }
    vector<vector<int> > psum(N+1,vector<int>(N+1,0));
    REP(i,N+1)FOR(j,1,N+1){
        psum[i][j]+=psum[i][j-1]+plane[i][j];
    }
    REP(j,N+1)REP(i,N){
        psum[i+1][j]+=psum[i][j];
    }

    ll res=1LL<<63-1;
    
    REP(i,N)REP(j,N)REP(k,N)REP(l,N){
        int x1=wx[i],x2=wx[j],y1=wy[k],y2=wy[l];
        if(!(x2>x1 && y2>y1)) continue;
        if(K>psum[x2][y2]+psum[x1-1][y1-1]-psum[x2][y1-1]-psum[x1-1][y2]) continue;
        res=min(res,(vx[j]-vx[i])*(vy[l]-vy[k]));
    }
    cout<<res<<endl;
    return 0;
}