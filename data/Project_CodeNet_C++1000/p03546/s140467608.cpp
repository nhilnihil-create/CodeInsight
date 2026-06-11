#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

ll d[10][10];

int main(){
    int h,w;
    cin>>h>>w;
    rep(i,10){
        rep(j,10){
            cin>>d[i][j];
        }
    }

    rep(k,10){
        rep(i,10){
            rep(j,10){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

    ll ans=0;
    rep(i,h){
        rep(j,w){
            int a;
            cin>>a;
            if(a==-1) continue;
            ans+=d[a][1];
        }
    }

    cout<<ans<<endl;
}