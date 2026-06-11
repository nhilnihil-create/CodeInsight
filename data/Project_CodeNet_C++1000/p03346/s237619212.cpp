#include<bits/stdc++.h>
using namespace std;

int dp[200100]={};

int main(){
    int N; cin >> N;
    int p[N];
    int ind[N+1];
    for(int i=0;i<N;i++){
        cin >> p[i];
        ind[p[i]]=i;
    }
    bool used[N+1]={};
    used[p[0]]=true;
    dp[0]=1;
    for(int i=1;i<N;i++){
        if(used[p[i]-1]){
            dp[i]=dp[ind[p[i]-1]]+1;
            used[p[i]]=true;
        }else{
            used[p[i]]=true;
            dp[i]=1;
        }
    }
    int ans=0;
    /*
    for(int i=0;i<N;i++){
        cout << dp[i] << " ";
    }
    */
    cout << endl;
    for(int i=0;i<N;i++){
        ans=max(dp[i],ans);
    }
    cout << N-ans << endl;
}