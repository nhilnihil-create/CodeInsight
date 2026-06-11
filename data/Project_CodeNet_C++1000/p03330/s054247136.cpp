#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N,C;
    cin>>N>>C;
    vector<vector<int>>d(C,vector<int>(C)),c(N,vector<int>(N));
    rep(i,C)rep(j,C)cin>>d[i][j];
    rep(i,N)rep(j,N){
        cin>>c[i][j];
        c[i][j]--;
    }
    int ans=1001001001;
    vector<vector<int>>sum(C,vector<int>(3));
    rep(i,C){
        int cnt1=0,cnt2=0,cnt3=0;
        rep(a,N)rep(b,N){
            if((a+b)%3==0)cnt1+=d[c[a][b]][i];
            if((a+b)%3==1)cnt2+=d[c[a][b]][i];
            if((a+b)%3==2)cnt3+=d[c[a][b]][i];
        }
        sum[i][0]=cnt1;
        sum[i][1]=cnt2;
        sum[i][2]=cnt3;
    }
    rep(i,C)rep(j,C)rep(k,C){
        if(i==j||j==k||k==i)continue;
        int cnt=sum[i][0]+sum[j][1]+sum[k][2];
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
}