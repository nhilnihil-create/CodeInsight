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

ll func(ll n){
	ll i=0;
	if(n==0) return 0;
	if(n==1) return 1; 
	while(2*i+1 <= n) i=2*i+1;

	if(i==n) return 0;
	ll j=i+1;
	ll k=j;                                 
	while(j<n){
		k=k^(j+1);
		j++;
	}
	return k;
}
ll a,b;
ll solve(ll a,ll b){
	if(a%2==0 && b%2) return ((b-a+1) %4==0)? 0 : 1;
	if(a%2==0 && b%2==0){
		return solve(a,b+1) ^ (b+1);
	} 
	if(a%2 && b%2 ){
		return solve(a+1,b)^a;
	}
	if(a%2 && b%2==0){
		return solve(a+1,b)^a;
	}
}


int main(){
	startTime=clock();
	cin >> a >> b;
	//cout << func(6)<< " "<< f(6)<<"\n";

	
	cout << solve(a,b);		
	return 0;
}