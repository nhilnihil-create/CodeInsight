#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll =long long;
using namespace std;
using graph=vector<vector<int>>;
using field=vector<string>;
using p =pair<int,int>;
const ll mod=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int main(){
    int d,G;
    cin>>d>>G;
    vector<int> p(d);
    vector<int> c(d);
    rep(i,d)cin>>p[i]>>c[i];
    int ans=mod;
    for(int i=0;i<pow(2,d);++i){
        int sum=0;
        int cnt=0;
        int temp=0;
        rep(j,d){
            if((i>>j)&1){
                sum+=(c[j]+p[j]*100*(j+1));
                cnt+=p[j];
            }else{
                temp=j;
            }
        }
        rep(l,p[temp]){
            if(sum>=G)break;
            sum+=(temp+1)*100;
            ++cnt;
        }
        if(sum>=G){
            ans=min(ans,cnt);
        }
    }
    cout<<ans<<endl;
}