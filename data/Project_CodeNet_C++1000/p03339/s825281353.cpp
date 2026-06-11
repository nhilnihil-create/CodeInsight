#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int N;
    string S;
    cin>>N>>S;
    vector<int> dplw(N),dpre(N);
    int allE=0,allW=0;//全体の東向きの人の数と西向きの人の数
    //dplw[i]:=i番目の人の左側にいる,西を向いている人の総数
    //dpre[i]:=i番目の人の右側にいる,東を向いている人の総数
    dplw[0]=0;
    dpre[N-1]=0;//初期値
    rep(i,N){
        if(S.at(i)=='E'){
            allE++;
        }
    }
    allW=N-allE;
    rep2(i,1,N){
        if(S.at(i-1)=='W'){
            dplw[i]=dplw[i-1]+1;
        }else{
            dplw[i]=dplw[i-1];
        }
    }
    for(int i=N-1;i>0;i--){
        if(S.at(i)=='E'){
            dpre[i-1]=dpre[i]+1;
        }else{
            dpre[i-1]=dpre[i];
        }
    }
    int ans=1000000;
    //i番目の人がリーダーになった時の転換回数は、dplw[i]+dpre[i]
    rep(i,N){
    //   cout << dplw[i] << " " << dpre[i]<<endl;
        ans=min(ans,dplw[i]+dpre[i]);
    }
    cout << ans << endl;
    return 0;
}