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
	int q=1e5+1;
	bool isprime[q];
	FOR(i,q) isprime[i]=true;
	for(int i=2;i<q;i++){
		if(isprime[i]){
			for(int j=2;j*i <q;j++) isprime[j*i]=false;
		}
	}
	isprime[1]=false;
	isprime[0]=false;
	bool is2017[q];
	FOR(i,q) is2017[i]=isprime[i] && isprime[(i+1)/2] && i%2;
	int sum[q]={};
	sum[0]=0;
	sum[1]=0;
	for(int i=2;i<q;i++){
		sum[i]=is2017[i]+sum[i-1];
	}

	int n,l,r;
	cin >> n;
	FOR(i,n){
		cin >> l >> r;
		if(is2017[l]) cout << 1+sum[r]-sum[l];
		else cout << sum[r]-sum[l];
		cout <<"\n";
	}
	return 0;
}