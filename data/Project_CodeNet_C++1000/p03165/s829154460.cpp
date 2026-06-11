#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<deque>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<map>
#include<stack>
#include<set>
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn =1000100;
typedef pair<ll,ll>p1;
typedef pair<pair<ll,ll>,ll>p2;
map<pair<pair<ll,ll>,ll>,ll>m1;
map<pair<ll,ll>,ll>m2;
const int MOD = 1e9;
const int N=351;
const int inf = 0x3f3f3f3f;
typedef pair<char, int> PAIR;
map<string,int>mm;
char a[maxn],b[maxn];
int dp[3003][3003];
int main()
{
    scanf("%s",a);
    scanf("%s",b);
    int n=strlen(a);
    int m=strlen(b);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i+1][j+1]+1;
            }else
            {
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        } 
     }
     int i=0;
    int j=0;
    while(i<n&&j<m)
    {
        if(a[i]==b[j])
        {
            printf("%c",a[i]);
            i++;
            j++;
        }else if(dp[i][j]==dp[i+1][j])
        {
            i++;
        }else
        {
            j++;
        }
    }
}