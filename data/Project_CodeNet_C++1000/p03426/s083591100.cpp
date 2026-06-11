#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
int main(void){
    int h,w,d;cin>>h>>w>>d;
    vector<vector<int>> a(h,vector<int>(w));
    map<int,pair<int,int>> mp;
    rep(i,h)rep(j,w){
        int a;
        cin>>a;a--;
        mp[a]={i,j};
    }
    vector<int> D(90003,0);
    rep(i,d){
       int tmp=0;
       int y=mp[i].first,x=mp[i].second;
       //cout<<y<<" "<<x<<endl;
       for(int j=1;d*j+i<h*w;j++){
           int ny=mp[j*d+i].first,nx=mp[j*d+i].second;
           tmp+=abs(ny-y)+abs(nx-x);
           //cout<<d*j+i<<" "<<ny<<" "<<nx<<endl;
           D[j*d+i]=tmp;
           y=ny;x=nx;
       }
    }
    //rep(i,h*w)cout<<D[i]<<endl;
    int q;cin>>q;
    rep(i,q){
        int l,r;cin>>l>>r;l--;r--;
        int res=D[r]-D[l];
        cout<<res<<endl;
    }
}
