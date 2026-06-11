#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,C;cin>>n>>C;
    int d[C][C];
    map<int,int> mp1,mp2,mp3;
    rep(i,C)rep(j,C){
        cin>>d[i][j];
    }
    rep(i,n)rep(j,n){
        int c;cin>>c;c--;
        if((i+j)%3==0)mp1[c]++;
        else if((i+j)%3==1)mp2[c]++;
        else mp3[c]++;
    }
    ll res=1e+9;
    rep(i,C)rep(j,C)rep(k,C){
        if(i==j||k==j||k==i)continue;
        ll tmp=0;
        for(auto& p:mp1){
            int x=p.first,y=i;
            tmp+=p.second*(d[x][y]);
        }
        for(auto& p:mp2){
            int x=p.first,y=j;
            tmp+=p.second*(d[x][y]);
        }
        for(auto& p:mp3){
            int x=p.first,y=k;
            tmp+=p.second*(d[x][y]);
        }
        chmin(res,tmp);
    }
    cout<<res<<endl;
}