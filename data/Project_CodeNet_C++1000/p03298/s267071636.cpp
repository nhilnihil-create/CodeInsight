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

int n;
ll cnt;
string s,m,m2;
bool b[18];
map<pair<string,string>,ll>mp;

int main() {
	cin>>n>>s;
	rep(1<<n){
		m="";
		m2="";
		int k=i;
		REP(n,j){
			if(k%2)m+=s[j];
			else m2+=s[j];
			k/=2;
		}
		mp[mkp(m,m2)]++;
	}
	cnt=0;
	rep(1<<n){
		m="";
		m2="";
		int k=i;
		REP(n,j){
			if(k%2)m+=s[2*n-1-j];
			else m2+=s[2*n-1-j];
			k/=2;
		}
		cnt+=mp[mkp(m,m2)];
	}
	cout<<cnt<<endl;
	return 0;
}
