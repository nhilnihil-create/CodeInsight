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
int n,m,x,t;
int *k;
int *p;
bool checkForDigit(int n,int i){
	return (n & 1 << i);
}

int main(){
	startTime=clock();
	cin >> n >> m ;
	int b[m][n];

	FOR(i,n) FOR(j,m) b[j][i]=0;
	FOR(i,m){
		cin >> x;
		FOR(j,x){
			cin >> t;
			b[i][t-1]++;
		}
	}
	bool flag;
	p=new int [m];
	int ans=0;
	FOR(i,m) cin >> p[i];
	for(int i=0; i < (1<< n) ; i++){
		flag=true;
		FOR(j,m){
			t=0;
			FOR(k,n){
				if(b[j][k] & checkForDigit(i,k)) t++;
			}
			if((t-p[j])%2==0) ;
			else {flag=false; break;}
		}
		if(flag==true) ans++;
		
	}
	cout << ans;
	

	return 0;
}