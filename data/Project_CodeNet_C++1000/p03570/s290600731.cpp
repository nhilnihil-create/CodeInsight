#include "bits/stdc++.h"
#define MAXN 200009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
char s[MAXN];
int dp[1<<26];
int main(){
    //~ freopen("file.in", "r", stdin);
    scanf("%s",s);
    for(int i=1;i<(1<<26);i++)
		dp[i]=INF;
    int n=strlen(s),mask=0;
    for(int i=0;i<n;i++){
		mask^=(1<<(s[i]-'a'));
		int ans=dp[mask];
		if(!ans)
			ans++;
		for(int j=0;j<26;j++)	
			umin(ans,dp[mask^(1<<j)]+1);
		if(i==n-1)
			printf("%d\n",ans);
		umin(dp[mask],ans);	
	}
	return 0;
}
