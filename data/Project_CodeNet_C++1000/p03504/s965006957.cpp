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
    cin>>N>>C;
    vector<vector<int>> ch(C,vector<int>(1e+5,0));
    int s,t,c;
    REP(i,N){
        cin>>s>>t>>c;
        c--;
        s--;
        REP2(j,s,t) ch[c][j]=1;
    }

    int ans=0;
    int cnt=0;
    REP2(x,0,1e+5){
        cnt=0;
        REP(i,C){
            cnt+=ch[i][x];
        }
        ans=max(cnt,ans);
    }
    cout << ans << endl;
    
    
}