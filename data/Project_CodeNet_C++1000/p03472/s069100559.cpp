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
ll *a;
ll *b;
ll h;
int main(){
	startTime=clock();
	cin >> n >> h;
	a=new ll[n];
	b=new ll[n];
	FOR(i,n){
		cin >> a[i] >> b[i];
	}
	ll ans=0;
	sort(b,b+n);
	ll maxx=0;
	FOR(i,n){
		maxx=max(maxx,a[i]);
	}
	//ll sum=0;
	int i=n-1;
	int j=0;
	while(b[j]<= maxx) j++;
	while(h>0 && i >j-1){
		h-=b[i];
		i--;
		ans++;	
	}
	//error(ans,j,h);
	if(h > 0){
		ans+= h/maxx ;
	}
	if(h/maxx * maxx < h) ans++;
	cout << ans;

	return 0;
}
