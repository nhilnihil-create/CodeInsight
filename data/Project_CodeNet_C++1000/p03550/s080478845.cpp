#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

template<class T> inline bool chmax(T& a, T b){ if (a<b){a=b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b){ if (a>b){a=b; return 1;} return 0;}
const long long INF=1LL << 60;

int main(){
    int N,Z,W;
    cin >> N >> Z >> W;
    vector<long long> V(N);
    for(int i=0;i<N;i++) cin >> V[i];

    vector<vector<long long> > DP(N+1,vector<long long>(2));//DP[i][j]:すでにi番目のカードまでを引いていて、if 先手 :j=0

    for(int i=N-1; i>=0;i--){
        //先手
        DP[i][0]= -INF;
        long long Y = (i ? V[i-1]: W);//後手の持っているカード i>0の時、i-1番目を取ったのは、後手だから
        chmax(DP[i][0],abs(Y- V[N-1]));//最大か
        
        for(int j=i+1;j<N;j++) chmax(DP[i][0],DP[j][1]);

        //後手番
        DP[i][1]= INF;
        long long X = (i ? V[i-1] :Z);
        chmin(DP[i][1], abs(X - V[N-1]));
        for(int j=i+1;j<N;j++) chmin(DP[i][1],DP[j][0]);
    }
    cout << DP[0][0] << endl;
}
