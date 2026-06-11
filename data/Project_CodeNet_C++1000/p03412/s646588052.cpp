#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"
#include "stack"
#include "tuple"

#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 92233720368547758070
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define mkt make_tuple
#define P pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;

int n,cnt=0,ans=0,c;
vector<int> a,b;
int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>c;
		a.push_back(c);
	}
	for(int i=0;i<n;++i){
		cin>>c;
		b.push_back(c);
	}
	for(int i=29;i!=-1;--i){
		for(int j=0;j<n;++j){
			a[j]%=(1<<i+1);
			b[j]%=(1<<i+1);
		}
		sort(b.begin(),b.end());
		cnt=0;
		for(int j=0;j<n;++j){
			cnt+=b.end()-lower_bound(b.begin(),b.end(),(1<<(i+1))+(1<<i)-a[j]);
			cnt%=2;
			cnt+=lower_bound(b.begin(),b.end(),(1<<(i+1))-a[j])-lower_bound(b.begin(),b.end(),(1<<i)-a[j]);
			cnt%=2;
		}
		if(cnt)
			ans+=(1<<i);
	}
	cout<<ans<<endl;
	return 0;
}