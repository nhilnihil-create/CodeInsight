#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))
#define iter(v,ite) for(auto ite=(v).begin();ite!=(v).end();ite++)
#define mimunum(v,x) distance((v).begin(),lower_bound((v).begin(),(v).end(),x))

char s[200005];

int dp[1<<26];

int main(void){
	memset(dp,-1,sizeof(dp));
	scanf("%s",s);
	int ls=strlen(s);
	dp[0]=0;
	int np=0;
	rep(i,ls){
		np ^= (1<<(s[i]-'a'));
		int na=dp[np];
		rep(j,26){
			int tp=np ^ (1<<j);
			if(dp[tp]>=0 && (na<0 || dp[tp]<na)){
				na=dp[tp];
			}
		}
		if(na>=0){
			if(dp[np]<0 || na+1<dp[np])dp[np]=na+1;
		}
		//printf("%d %d\n",np,na);
	}
	
	printf("%d\n",max(dp[np],1));
	return 0;
}




