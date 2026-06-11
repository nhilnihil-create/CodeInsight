#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using Graph=vector<vector<int>>;
typedef long long ll;

int rui(int N,int K){
    int A=1;
    if(K==0){
        return 1;
    }
    else{
        rep(i,K){
            A=A*N;
        }
        return A;
    }
}

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
    int N;
    cin>>N;
    vector<int>list;
    rep(i,5){
        list.push_back(rui(9,i+1));
    }
    rep(j,6){
        list.push_back(rui(6,j+1));
    }
    sort(list.begin(),list.end());
    reverse(list.begin(),list.end());
    vector<int>dp(N+1,1e9+7);//k円出すときの最短路
    dp[0]=0;
    for(int i=1;i<N+1;i++){
        dp[i]=1+dp[i-1];
        rep(j,list.size()){
            if(i>=list[j]){
                chmin(dp[i],dp[i-list[j]]+1);
            }
        }
    }
    cout<<dp[N]<<endl;
}
