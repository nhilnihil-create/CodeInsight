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
	ll n;
	cin >> n;
	ll array[n];
	ll sum[n+1];
	ll count=0;
	sum[0]=0;
	FOR(i,n){
		cin >> array[i];
		sum[i+1]= sum[i]+array[i] ;  
	}
	sort(sum,sum+n+1);
	ll i=0;
	while(i< n+1 ){
		ll j=i;
		while(j<n+1 && sum[i]==sum[j])j++;
		count+=((j-i)*(j-i-1))/2;
		i=j;
	}
	cout << count;
	return 0;
}