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
    int N,K;
    cin>>N>>K;
    string S;
    cin>>S;
    vector<int> A;
    A.push_back(0);
    REP(i,N-1){
        if(S[i]!=S[i+1]) A.push_back(i+1);
    }
    A.push_back(N);
    
    int ans=0;
    REP(i,A.size()){
        int l=A[i];
        int j,r;
        if(l==0) j=i+2*K;
        else if(S[l-1]=='1') j=i+2*K;
        else j=i+2*K+1;
        r=A[min(j,(int)A.size()-1)];
        ans=max(ans,r-l);
    }
    cout<<ans<<endl;
    
}