#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
typedef pair<int,int> P;
const int INF=1e9;
int main(){
    ll d,g,ans=INF;
    cin>>d>>g;
    vector<ll> p(d),c(d);
    rep(i,d) cin>>p[i]>>c[i];
    rep(i,1<<d){
        ll sum=0,dd=0;
        vector<ll> hantei=p;
        rep(j,d){
            if(i>>j&1){
                sum+=(j+1)*p[j]*100+c[j];
                dd+=p[j];
                hantei[j]=0;
            }
        }
        if(sum>=g) ans=min(ans,dd);
        else{
            for(int j=d-1;j>=0;j--){
                if(hantei[j]){
                    while(sum<g&&hantei[j]){
                        dd++;
                        sum+=(j+1)*100;
                        hantei[j]--;
                    }
                    if(sum>=g) ans=min(ans,dd);
                    break;
                }
            }
        }
    }
    cout<<ans;
}