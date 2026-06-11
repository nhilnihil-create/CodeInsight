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

ll minar=1e18;
int main(){
	startTime=clock();
	int n;
	bool flag=false;
	int count=0;
	ll sum=0;
	cin >> n;
	int ar[n];
	FOR(i,n){
		cin >> ar[i];
		if(ar[i]==0) flag=true;
		if(!flag && ar[i] < 0) count++;
		ar[i]=abs(ar[i]);
		minar=min((ll) ar[i],minar);
		sum+=ar[i];
	}
	if(!flag){
		if(count % 2) sum-=2*minar;
	}
	cout << sum;
	return 0;
}