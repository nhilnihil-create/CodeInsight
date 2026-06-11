#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
//typedef pair<int, int> P;
//typedef pair<int, pair<int, int> > PP;
const int MAX=2e5+10;
const ll INF=9e18;

int main(){
	int N;
	ll X;
	cin>>N>>X;
	ll x[MAX];
	rep1(i,N)cin>>x[i];
	ll sum[MAX];
	sum[0]=0;
	rep1(i,N)sum[i]=sum[i-1]+x[i];
	ll ans=INF;
	rep1(k,N){
		bool ed=false;
		ll tmp=sum[N]*5+X*(N+k);
		for(int p=N-2*k; p>=1; p-=k){
			tmp+=2*sum[p];
			if(ans<=tmp){
				ed=true;
				break;
			}
		}
      	if(!ed)ans=min(ans, tmp);
	}
	cout<<ans<<endl;
}