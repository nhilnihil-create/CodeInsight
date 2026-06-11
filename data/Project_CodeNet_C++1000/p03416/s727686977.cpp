/* FUCK U*/
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <iterator>
typedef long long ll;
typedef long double ld;
using namespace std;
typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e5+50;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define f first
#define s second
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
ll pow(ll x, ll y, ll mod)
{
	int ans=1;
	while(y)
	{
		if(y&1)
			ans=(ans*x)%mod;
		y/=2;
		x=(x*x)%mod;
	}
	return ans;
}

void solve(){
    int n,k,count;
   
    cin>>n>>k;
    for(int i=n;i<=k;++i){
       string str=to_string(i);
        if(str.at(0)==str.at(4) && str.at(1)== str.at(3))
            count++;
    }
    cout<<count<<endl;    

}
int main(){
 
   ios::sync_with_stdio(false);
  cin.tie(0);
     solve();
}