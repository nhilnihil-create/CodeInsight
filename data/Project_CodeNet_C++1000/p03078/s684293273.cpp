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
    int X,Y,Z,K;
    cin>>X>>Y>>Z>>K;
    vector<ll> A(X),B(Y),C(Z);
    REP(i,X){
        cin>>A[i];
    }
    REP(i,Y){
        cin>>B[i];
    }
    REP(i,Z){
        cin>>C[i];
    }
    priority_queue<ll> AB,AB_K,ABC;
    REP(i,X){
        REP(j,Y){
            AB.push(A[i]+B[j]);
        }
    }
    ll tmp;
    REP(i,K){
        if(AB.empty()) break;
        tmp=AB.top();
        AB.pop();
        AB_K.push(tmp);
    }
    ll tmp2;
    while(!AB_K.empty()){
        tmp=AB_K.top();
        AB_K.pop();
        REP(i,Z){
            tmp2=tmp+C[i];
            ABC.push(tmp2);
        }
    }

    int cnt=1;
    while(!ABC.empty()){
        tmp=ABC.top();
        cout<<tmp<<endl;
        if(cnt==K){
            return 0;
        }
        cnt++;
        ABC.pop();
    }
}