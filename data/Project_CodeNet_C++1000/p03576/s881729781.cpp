//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const ll INF=6e+18;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//グローバル変数


//ライブラリ挿入


int main(){
    int N,K;
    cin >> N >> K;
    vector<ll> x(N),y(N);
    REP(i,N) cin >> x[i]>>y[i];
    ll x_max,x_min;
    ll y_max,y_min;
    ll ans=INF;
    int cnt=0;
    if(K==2){
        REP(i,N-1){
            REP2(j,i+1,N){
                x_max=max(x[i],x[j]);
                y_max=max(y[i],y[j]);
                x_min=min(x[i],x[j]);
                y_min=min(y[i],y[j]);
                cnt=4;
                REP(k,N){
                    if(k==i||k==j) continue;
                    if(x[k]<=x_max&&y[k]<=y_max&&x[k]>=x_min&&y[k]>=y_min) cnt++;
                }
                if(cnt>=K){
                    ans=min(ans,(x_max-x_min)*(y_max-y_min));

                }
            }
        }
    }

    if(K==3){
        REP(i,N-2){
            REP2(j,i+1,N-1){
                REP2(l,j+1,N){
                    x_max=max(max(x[i],x[j]),x[l]);
                    y_max=max(max(y[i],y[j]),y[l]);
                    x_min=min(min(x[i],x[j]),x[l]);
                    y_min=min(min(y[i],y[j]),y[l]);
                    cnt=4;
                    REP(k,N){
                        if(k==i||k==j||k==l) continue;
                        if(x[k]<=x_max&&y[k]<=y_max&&x[k]>=x_min&&y[k]>=y_min) cnt++;
                    }
                    if(cnt>=K){
                        ans=min(ans,(x_max-x_min)*(y_max-y_min));

                    }
                    
                }
            }
        }
    }
    if(K>=4){
        REP(i,N-3){
            REP2(j,i+1,N-2){
                REP2(l,j+1,N-1){
                    REP2(m,l+1,N){
                        x_max=max(max(x[i],x[j]),max(x[l],x[m]));
                        y_max=max(max(y[i],y[j]),max(y[l],y[m]));
                        x_min=min(min(x[i],x[j]),min(x[l],x[m]));
                        y_min=min(min(y[i],y[j]),min(y[l],y[m]));
                        cnt=4;
                        REP(k,N){
                            if(k==i||k==j||k==l||k==m) continue;
                            if(x[k]<=x_max&&y[k]<=y_max&&x[k]>=x_min&&y[k]>=y_min) cnt++;
                        }
                        if(cnt>=K){
                            ans=min(ans,(x_max-x_min)*(y_max-y_min));

                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    
}