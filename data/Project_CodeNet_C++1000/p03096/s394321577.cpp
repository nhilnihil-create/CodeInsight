#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

vector<int>places[200010];
long long dp[200010];
void add(long long &a,long long b){
    a+=b;
    if(a>=mod)a-=mod;
    return;
}
//status unsolved

int main(){
    int n;
    cin>>n;
    int color[n];
    rep(i,n)cin>>color[i];
    
    rep(i,n)places[i].clear();
    
    //places[i]:=(c[j]=iとなるjの集まり)
    rep(i,n)places[color[i]].push_back(i);

    //もっとも左で区切る=何もしない時
    dp[0]=1;
    for(int i=1;i<=n;i++){

        //何もしない時
        add(dp[i],dp[i-1]);

        int col=color[i-1];
        //同じ色で現在地より左にあるものの番号を取得
        int it=lower_bound(places[col].begin(),places[col].end(),i-1)
        -places[col].begin();

        if(it>0){
            
            int j=places[col][it-1];
            //cout<<i<<" "<<j<<" ";
            //同じ色が並んでいたら何もしない
            //(現在見ている石:=i-1番目の石)
            if(j>=i-2)continue;

            add(dp[i],dp[j+1]);
        }
        //cout<<dp[i]<<" "<<endl;;
    }
    //cout<<endl;
    cout<<dp[n]<<endl;

    return 0;

}
/*


*/
