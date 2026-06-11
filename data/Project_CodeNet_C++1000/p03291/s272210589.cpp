#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
string solve(bool a) { return ((a) ? "Yes" : "No"); }
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
template <class T, class U>ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}
template <class T>ostream& operator<<(ostream& os, const vector<T>& v) {
	os << "{";
	rep(i, v.size()) {
		if (i) os << ",";
		os << v[i];
	}
	os << "}";
	return os;
}
template <class T, class U>istream& operator>>(istream& is, pair<T, U>& p) {
	is >> p.first >>p.second ;
	return is;
}
template <class T>istream& operator>>(istream& is,  vector<T>& v) {
	rep(i, v.size()) {
		is >> v[i];
	}
	return is;
}
long long modpow(long long a, long long n, long long mod=(1LL<<62)){
	long long res = 1;
	while (n > 0){
		if (n & 1)
		res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
ll mod                = 1e9 + 7;
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	string s;
	ll ans=0LL;
	cin >>s;
	int pool = 0;
	V data(3,0LL);//a,ab,abc
	for (int i = 0; i < s.size();i++){
		switch(s[i]){
			case 'A':
				data[0] +=1*modpow(3,pool,mod);
				data[0] %= mod;
				break;
			case 'B':
				data[1] += data[0];
				data[1] %= mod;
				break;
			case 'C':
				data[2] += data[1];
				data[2] %= mod;
				break;
			case '?':
				data[2] *= 3;
				data[2] %= mod;
				data[2] += data[1];
				data[2] %= mod;

				data[1] *= 3;
				data[1] %= mod;
				data[1] += data[0];
				data[1] %= mod;

				data[0] *= 3;
				data[0] %= mod;
				data[0] += modpow(3,pool,mod);
				data[0] %= mod;
				/*
		
				
				*/
				pool++;
				break;
		}
	//	clog << data << endl;
	}
	 cout << data[2] << endl;
}
/*
A??C

4 2*2 2*2 3

AA 2
AB 1 2 1
AC 1 = 7




???
1 0 0

1
2 2 2
4 4 4 4 4 4 3 = 24 +3

AA 2
AB 1 2 1
AC 1
BA 1
CA 1 = 9

15 1 0
6 7 0
6 1 1

*/

/*
尺取り方
a,
ab
abc
*/