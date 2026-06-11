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

#define rep(n) for (int i = 0; i < n; ++i)
#define REP(n,i) for (int i = 0; i < n; ++i)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define mkt make_tuple
#define P pair<ll, ll>
typedef long long ll;
using namespace std;

int n,k,a[100000],b[100000];
ll mx,cnt;

int main() {
	cin>>n>>k;
	mx=0;
	rep(n){
		cin>>a[i]>>b[i];
		if((k|a[i])==k)mx+=b[i];
	}
	rep(30){
		if((k%(1<<(i+1)))/(1<<i)%2){
			k=k-k%(1<<(i+1))+(1<<i)-1;
			cnt=0;
			REP(n,j)
				if((k|a[j])==k)cnt+=b[j];
//			cout<<cnt<<sp<<bitset<10>(k)<<endl;
			mx=max(mx,cnt);
		}
	}
	cout<<mx<<endl;
	return 0;
}
