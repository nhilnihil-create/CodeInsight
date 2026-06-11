//author: dxm
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath> 
#include<cstring> 
#include<cassert>
#include<string>
#include<sstream>
#include<fstream>
#include<deque>
#include<queue>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<set>
#include<bitset>
#include<iomanip>
#include<utility>
#include<functional>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cwchar>
#include<cwctype>
#include<exception>
#include<locale>
#include<numeric>
#include<new>
#include<stdexcept>
#include<limits>
using namespace std;

#define ll long long
#define INF 1e9
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
inline void Fail(){
	printf("0");
	exit(0);
}

const int maxn=200005;
int n;
int dp[maxn],a[maxn];
char c[maxn];
map<int,int>m;
int cur;

int main(){
	scanf("%s",c);
	n=strlen(c);
	rep(i,n)a[i]=c[i]-'a';
	m[0]=0;
	rep(i,n){
		dp[i]=INF;
		cur^=(1<<a[i]);
		if(m.find(cur)!=m.end())dp[i]=min(dp[i],m[cur]+1);
		rep(j,26){
			int tmp=cur^(1<<j);
			if(m.find(tmp)!=m.end())dp[i]=min(dp[i],m[tmp]+1);
		}
		dp[i]=min(dp[i],(!i?0:dp[i-1])+1);
		if(m.find(cur)==m.end())m[cur]=dp[i];
		else m[cur]=min(m[cur],dp[i]);
//		cout<<dp[i]<<endl;
	}
	printf("%d",dp[n-1]);
	return 0;
}

/*
Input:
aabxyyzz

byebye

abcdefghijklmnopqrstuvwxyz

abcabcxabcx
-----------------
Output:
2

1

26

3
*/