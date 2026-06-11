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

int main(){
	startTime=clock();
	int n;
	cin >> n;
	ll a[n],b[n];
	ll k=0;
	ll sum=0;
	FOR(i,n){
		cin >> a[i];
	}
	FOR(i,n){
		cin >> b[i];
	}
	FOR(i,n){
		sum+=b[i]-a[i];

		if(a[i] < b[i])
		k+=(b[i]-a[i]+1)/2;
	}
	
	if(sum < 0) {cout << "No"; return 0;}
	else if(k > sum) cout << "No";
	else cout << "Yes"; 


	return 0;
}