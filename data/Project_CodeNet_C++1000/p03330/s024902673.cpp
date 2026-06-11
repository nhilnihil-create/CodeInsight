#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<int,ll> P;

ll d[32][32];
ll now[510][510];
ll r[3]={0,1,2};

ll cost[5][35];

int main(){
    ll n,C;
    cin>>n>>C;
    for(int i=0;i<C;i++){
        for(int j=0;j<C;j++){
            cin>>d[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            a--;
            now[i][j]=a;
        }
    }
    ll ans = (ll)INF;
    for(ll r=0;r<3;r++){
        for(ll c=0;c<C;c++){
            ll tmp=0;
            for(ll x=0;x<n;x++){
                for(ll y=0;y<n;y++){
                    if((x+y)%3==r){
                        tmp+=d[now[x][y]][c];
                    }
                }
            }
            cost[r][c]=tmp;
        }
    }
    for(ll i=0;i<C;i++){
        for(ll j=0;j<C;j++){
            for(ll k=0;k<C;k++){
                if(i==j)continue;
                if(j==k)continue;
                if(k==i)continue;
                ll tmp = cost[0][i]+cost[1][j]+cost[2][k];
                //cout<<i<<" "<<j<<" "<<k<<" "<<tmp<<endl;
                ans = min(ans,tmp);
            }
        }
    }
    cout<<ans<<endl;
}
