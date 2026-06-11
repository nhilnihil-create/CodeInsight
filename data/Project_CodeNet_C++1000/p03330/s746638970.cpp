//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
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
    int N,C;
    cin >> N>>C;
    vector<vector<int>> D(C+2,vector<int>(C+2,0));
    vector<vector<int>> c(N+2,vector<int>(N+2,0));
    REP2(i,1,C+1){
        REP2(j,1,C+1){
            cin>>D[i][j];
        }
    }

    vector<vector<int>> v(3,vector<int>(C+1,0));
    REP2(i,1,N+1){
        REP2(j,1,N+1){
            cin>>c[i][j];
            v[(i+j)%3][c[i][j]]++;
        }
    }

    ll ans=INF;
    ll tmp;
    REP2(i,1,C+1){
        REP2(j,1,C+1){
            if(i==j) continue;
            REP2(k,1,C+1){
                
                if(j==k||i==k) continue;
                tmp=0;
                REP2(l,1,C+1){
                    tmp+=(v[0][l]*D[l][i]);
                    tmp+=(v[1][l]*D[l][j]);
                    tmp+=(v[2][l]*D[l][k]);
                }
                ans=min(ans,tmp);
            }   
        }
    }
    cout << ans << endl;

    


    
}