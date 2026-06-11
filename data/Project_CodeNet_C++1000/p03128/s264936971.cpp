#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M; cin >> N >> M;
    int num[10]={2,5,5,4,5,6,3,7,6};
    int a[M];
    for(int i=0;i<M;i++) cin >> a[i];
    string dp[11000];
    for(int i=0;i<=N;i++) dp[i]="-";
    dp[0]="";
    for(int i=0;i<=N;i++){
        for(int j=0;j<M;j++){
            if(dp[i]=="-") continue;
            int x=dp[i+num[a[j]-1]].size();
            int y=(dp[i]+to_string(a[j])).size();
            if(dp[i+num[a[j]-1]]=="-"){
                dp[i+num[a[j]-1]]=dp[i]+to_string(a[j]);
            }else if(x<y){
                dp[i+num[a[j]-1]]=dp[i]+to_string(a[j]);
            }else if(x==y&&dp[i+num[a[j]-1]]<(dp[i]+to_string(a[j]))){
                dp[i+num[a[j]-1]]=dp[i]+to_string(a[j]);
            }
        }
    }
    cout << dp[N] << endl;
}