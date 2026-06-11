#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int N;cin>>N;
    if(N==1){
        cout<<0<<endl;
    }
    else{
        vector<ll>Ans(N,0);
        Ans[0]=0;
        vector<ll>C(N-1);
        vector<ll>S(N-1);
        vector<ll>F(N-1);
        rep(i,N-1){
            cin>>C[i]>>S[i]>>F[i];
        }
        ll time=0;//開始からの時間
        Ans[N-1]=0;
        for(int i=0;i<N-1;i++){
            ll time=0;//スタート時
            for(int j=i;j<N-1;j++){//jは今いる駅
                if(time<=S[j]){
                    time=S[j];//スタートまでは待つ;
                    time=time+C[j];//次の駅に着くまでの時間
                }
                else{
                    ll T=time-S[j];//駅に着いた時点で最初の出発から何分?
                    if(T%F[j]==0){
                        time=time+C[j];//着いた瞬間電車出発
                    }
                    else{
                        time=time+F[j]-T%F[j]+C[j];
                    }
                }
            }
            Ans[i]=time;
        }
        rep(i,N){
            cout<<Ans[i]<<endl;
        }
    } 
}