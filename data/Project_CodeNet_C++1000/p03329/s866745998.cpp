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

int f6(int n){
	int i=1;
	while(i*6<=n) i*=6;
	return i;
}

int f9(int n){
	int i=1;
	while(i*9<=n) i*=9;
	return i;
}
int *dp;
int solve(int n){

	if(n<=5) return (dp[n]=n);
	else{
		int x=f9(n);
		int y=f6(n);
	return (dp[n]=1+min(solve(n-x),solve(n-y))); 
	} 
}

int main(){
	startTime=clock();
	int n;
	cin >> n;
	dp=new int[n+1];

	cout << solve(n);

	return 0;
}