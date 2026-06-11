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




ll ans=0;
ll n;

bool f(ll t){
	
	int a3=0,a5=0,a7=0,m=t;
	while(m>0){
		if(m%10==3) a3++;
		if(m%10==5) a5++;
		if(m%10==7) a7++;
		m/=10;
	}
	if(a3 && a5 && a7) return true;
	return false;
}


void func(ll k){
	if(k > n) return;
	else{
		 if(f(k)) ans++;
		 func(k*10+3);
		 func(k*10+5);
		 func(k*10+7);
	}
}
int main(){
	startTime=clock();
	
	cin >> n;
	
	func(0);
	cout << ans;
	return 0;
}