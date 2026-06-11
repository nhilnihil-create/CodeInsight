#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int M = 1000001;

int s[] = {0,2,5,5,4,5,6,3,7,6};
int a[M],ans[M];
int n,m;
int dp[M];

int cmp(int a,int b){
    return a > b;
}
 
int main(){
    cin>>n;
	cin>>m;
    for(int i = 0;i < m;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    dp[0] = 1;
 
    int vis[10] = {0};
    for(int i = 0;i < m;i++){
        for(int j = s[a[i]];j <= n;j++){
            dp[j] = max(dp[j],dp[j-s[a[i]]]+1);
        }
    }
 
    sort(a,a+m,cmp);
    while(n){
        for(int i = 0;i < m;i++){
            if(n >= s[a[i]] && dp[n-s[a[i]]]+1 == dp[n]){
                putchar(a[i]+'0');
                n = n-s[a[i]];
				break;
            }
        }
    }
 
    cout<<endl;
    return 0;
}