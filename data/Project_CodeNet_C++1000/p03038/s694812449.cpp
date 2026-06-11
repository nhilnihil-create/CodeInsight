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
int n,m;
ll *a;


int findpos(ll x,int curr){
	for(int i=n; i > 0; i/=2)
		while(curr+i < n && a[curr+i]< x) curr+=i;
	return min(curr,n-1);
}



int main(){
	startTime=clock();
	cin >> n >> m;
	a=new ll[n];
	ll y;
	int x;
	std::vector<pair<ll,int>> w;
	FOR(i,n) cin >> a[i];
	FOR(i,m) {
		cin >> x >> y;
		w.PB(MP(y,x));
	}
	

	sort(a,a+n);
	sort(w.begin(),w.end());
	int curr=0;
	for(int i=m-1;i >=0;i--){
		int y=min(w[i].S+curr-1,findpos(w[i].F,curr));
		if(y >=n) break;
		while(curr <= y ) {
			a[curr]=max(w[i].F,a[curr]);
			curr++;
			
		}
	}
	
	

	ll sum=0;
	FOR(i,n) sum+=a[i];
	cout  << sum;
	
	//FOR(i,n) cout << "\n" << a[i];

	return 0;
}