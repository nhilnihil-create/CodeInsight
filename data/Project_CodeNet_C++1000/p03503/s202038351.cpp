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

ll INF=1e9+10;

int main(){
	startTime=clock();
	int n;
	cin >> n;
	int f[n][5][2];
	FOR(i,n)
		FOR(j,5)
			FOR(k,2)
				cin >> f[i][j][k];	
	int p[n][11];
	FOR(i,n)
		FOR(j,11)
			cin >> p[i][j];
	int match[n]={};
	ll profit=-INF;
	for(int i=1;i<1024;i++){
		int j=i;
		FOR(t,n) match[t]=0;
		FOR(t,10){
			if(j%2==1)
				FOR(i,n) if(f[i][t/2][t%2]) match[i]++;
			j/=2;
		}
		ll auxprofit=0;
		FOR(i,n) auxprofit+=p[i][match[i]];
		profit=max(profit,auxprofit);
	}	
	cout << profit;

	return 0;
		
}