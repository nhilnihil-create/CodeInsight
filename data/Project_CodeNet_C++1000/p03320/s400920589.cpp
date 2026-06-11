#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define FFOR(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define rep(i,n) FOR(i,0,n-1)
#define int long long
#define MOD 998244353
#define MAXN  100005
#define P pair<int,int>
 
int s(int n)
{
	int ans = 0;
	while(n) ans +=n%10,n/=10;
	return ans;	
}
 
 
signed main(){
	
	int k;cin>>k;
	
	int num = 1;
	int keta = 1;
	
	rep(i,k)
	{
		cout << num << endl; 
		while((num + keta)*s(num+2*keta) > (num + 2*keta)*s(num+keta)) keta *=10;
		num += keta;
	}
}