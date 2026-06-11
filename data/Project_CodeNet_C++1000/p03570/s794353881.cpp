#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int op[maxn],a[maxn],str[30];
int dp[1<<26];
#define inf  999999
int main()
{
    string s;
    int n;
    cin>>s;
    n=s.size();
    memset(str,0,sizeof(str));
    for(int i=0;i<n;i++){
        int bit=0;
        str[s[i]-'a']++;
        for(int j=0;j<26;j++){
             if(str[j]%2){
                 bit+=(1<<j);
             }
        }
        a[i+1]=bit;//表示前i个长度的字串，都有哪些字母是奇数个;
    }
   for(int i=0;i<1<<26;i++){
		dp[i] = inf;//表示在i状态下，能够满足题意得最少分解数目
	}
	for(int i=0;i<=n;i++) op[i] = inf;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        op[i]=min(op[i],dp[a[i]]+1);//最差的情况是前i-1的最佳结果加上1
        for(int j=0;j<26;j++){
            op[i]=min(op[i],dp[a[i]^(1<<j)]+1);//转移到（异或上任意一个字符再加上当前字符就最小）的那个状态
        }
        dp[a[i]]=min(dp[a[i]],op[i]);//更新当前状态
    }
    cout<<op[n]<<endl;
    return 0;
}
