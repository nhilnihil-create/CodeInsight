#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <ctime>
#include <unordered_map>
#include <iomanip>
#include <complex>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define deb(a) cerr<< #a << "= " << (a)<<"\n";

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;
typedef complex<double> base;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<class T> ostream& operator<<(ostream& stream, const vector<T> v){ stream << "[ "; for (int i=0; i<(int)v.size(); i++) stream << v[i] << " "; stream << "]"; return stream; }
ll fpow(ll x, ll p, ll m){ll r=1; for (;p;p>>=1){ if (p&1) r=r*x%m; x=x*x%m; } return r;}
ll inv(ll a, ll b){ return a<2 ? a : ((a-inv(b%a,a))*b+1)/a%b; }
int gcd(int a, int b){ if (!b) return a; return gcd(b,a%b);}
ll gcd(ll a, ll b){ if (!b) return a; return gcd(b,a%b);}

int N,A,B,a[300010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> A >> B;
	
	if (A+B-1>N || B<(N+A-1)/A){
		cout << -1 << "\n";
		return 0;
	}
	
	int p=1,i,k;
	for (k=0; k<=N-A; k++)
		if ((N-k+A-1)/A+k==B)
			break;
			
	
	for (i=N; i>k; i-=A){
		
		int l=max(k+1,i-A+1);
		
		
		while (l<=i)
			a[p++]=l++;
		
		
	}
	
	while (k)
		a[p++]=k--;
		
	for (i=1; i<=N; i++)
		cout << a[i] << " ";
	return 0;
}

