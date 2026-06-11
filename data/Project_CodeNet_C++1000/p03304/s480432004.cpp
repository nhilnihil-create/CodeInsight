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
 
 
ll dp[305][305][305];
 
 
int main(void){
	ll n,m,d;
	cin>>n>>m>>d;
	double ans = 0.0;
	if(d==0){
		ans = (double)(m-1)/n;
	}
	else{
		ans = (double)2*(n-d)*(m-1)/(n*n);
	}
	printf("%.10lf\n",ans);
    return 0;
}