#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include<random>
using namespace std;
#define N (1000000000+7)
#define M 998244353
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
 
const int inf = (int)1e9;

ll A(ll x){
    if(x>=0)return x;
    else return -x;
}
 
ll gcd(ll a, ll b) {
	if (b > a) {
		ll tmp = b;
		b = a;
		a = tmp;
	}
	if (a%b == 0)return b;
	else return gcd(b, a%b);
}
 
 
 map<int,int>mp;
 
 
 
int main(void){
	string s;
	cin>>s;
	int n = s.size();
	int sum = 0;
	vector<int>dp;
	dp.assign(n+1,inf);
	dp[0]=0;
	mp[0]=0;
	for(int i=0;i<n;i++){
		sum^=1<<(s[i]-'a');
		for(int j=0;j<26;j++){
			int bit = sum^(1<<j);
			if(mp.find(bit)!=mp.end()){
				dp[i+1]=min(dp[i+1],mp[bit]+1);
			}
		}
		if(mp.find(sum)!=mp.end()){
			dp[i+1]=min(dp[i+1],mp[sum]+1);
		}
		if(mp.find(sum)==mp.end()||mp[sum]>dp[i+1])mp[sum]=dp[i+1];
	}
	cout<<dp[n]<<endl;
    return 0;
}