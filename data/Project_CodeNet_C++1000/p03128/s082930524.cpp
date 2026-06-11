#include<bits/stdc++.h>
using namespace std;
int c[10]={100,2,5,5,4,5,6,3,7,6};
int main(){
    int n,m;cin >> n >> m;
    vector<bool> b(10);
    for(int i=0;i<m;i++){
        int a;cin >> a;
        b[a]=true;
    }
    vector<vector<bool>> dp(n+1,vector<bool>(n/2+1));
    dp[0][0]=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            if(dp[i][j]){
                for(int k=1;k<=9;k++){
                    if(i+c[k]<=n&&b[k]){
                        dp[i+c[k]][j+1]=true;
                    }
                }
            }
        }
    }
    int t=0;
    for(int i=0;i<n/2+1;i++){
        if(dp[n][i]){
            t=max(t,i);
        }
    }
    int num=n;
    vector<int> v;
    for(int i=t;i>0;i--){
        for(int j=9;j>=1;j--){
            if(b[j]&&num-c[j]>=0&&dp[num-c[j]][i-1]){
                v.push_back(j);
                num-=c[j];
                break;
            }
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<v.size();i++){
        cout << v[i];
    }
    cout << endl;
}