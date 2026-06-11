#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

#define ll int
#define pb push_back
#define ld long double
#define mp make_pair
#define F first
#define S second
#define pii pair<ll,ll> 

using namespace :: std;

const ll maxn=5100;
const long long inf=1e18+800;
long long A,B;

ll a[maxn];
ll bish[maxn][maxn];
ll kamt[maxn][maxn];

long long price(ll i,ll j){
	if(a[i]>a[j])return inf;
	if(kamt[i][j-1]+bish[i+1][j]!=(j-i-1))return inf;
	return kamt[i][j-1]*B+bish[i+1][j]*A;
}
long long dp[maxn];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	ll n;
	cin>>n>>A>>B;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=0;
	a[n+1]=n+1;
	n+=2;
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			kamt[i][j]=kamt[i][j-1];
			if(a[j]<a[i]){
				kamt[i][j]++;
			}	
		}		
	}
	for(ll j=0;j<n;j++){
		for(ll i=j-1;i>=0;i--){
			bish[i][j]=bish[i+1][j];
			if(a[j]<a[i]){
				bish[i][j]++;
			}	
		}		
	}
	dp[0]=0;
	for(ll i=1;i<n;i++){
		dp[i]=inf;
		for(ll j=0;j<i;j++){
			dp[i]=min(dp[i],dp[j]+price(j,i));
		}
	}
	cout<<dp[n-1];

}


















