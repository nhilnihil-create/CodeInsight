#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
clock_t startTime;
long double getTime(){
	return (long double)(clock()-startTime)/CLOCKS_PER_SEC;
}

int n;
int* c;
ll* s;
int* f;
ll sol=0;
void solve(){
	FOR(i,n-1){
		sol=0;
		for(int j=i;j < n-1;j++){
			if(j==i) sol+=s[j];
			else{
				ll r= sol%f[j];
				if(sol <= s[j]) sol=s[j];
				else if(r==0) ;
				else sol+=f[j]-r;
			}
			sol+=c[j];
		}
		cout << sol << "\n";
	}
	cout << 0;
}

int main(){
	startTime=clock();
	cin >> n;
	c=new int[n-1];
	s=new ll[n-1];
	f=new int[n-1];
	FOR(i,n-1){
		cin >> c[i] >> s[i] >> f[i];
	}
	solve();

	return 0;
}