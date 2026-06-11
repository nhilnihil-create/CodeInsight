#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
#define sz (1<<(26))
int a[maxn];            

int val[maxn];

int dp[sz];

int ans[maxn];

int main(){
    string s;
    cin>>s;
    int n= s.size();
    for (int i=0; i<n; i++) a[i+1]= s[i]-'a';
    for (int i=1; i<=n; i++){
        val[i]= val[i-1];
        val[i]^=(1<<a[i]);
    }

    for (int i=0; i<sz; i++) dp[i]= maxn;
    dp[0]=0;
    for (int i=1; i<=n; i++){
        int t= maxn;
        t= min(t, dp[val[i]])+1;
        for (int j=0; j<26; j++){
            t= min(t, dp[val[i]^(1<<j)]+1);
        }
        ans[i]= t;
        dp[val[i]]= min(dp[val[i]], t);
    }    
    cout<<ans[n]<<endl; 

}