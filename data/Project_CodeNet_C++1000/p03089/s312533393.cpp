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
int *b;
vector<int> v;

void solve(int x, int y){
	if(x > y)  ;
	else if(x==y) cout << b[x] <<"\n";
	else{
		int mina=n+1;
		for(int i=x;i <=y;i++) mina=min(b[i],mina);
		int posmin=y;
		while(b[posmin]!=mina)posmin--;
		cout << mina<<"\n";
		solve(posmin+1,y);
		solve(x,posmin-1);
	}
	
}

int solve1(){
	int i=n-1;
	if(i==-1) return 1;
	while(i >=0 &&  b[i]!=(i+1)) i--;
	if(i==-1) return 0;
	else {
		v.eb(i+1);
		for(int j=i+1;j < n;j++) b[j-1]=b[j];
		n--;
		return solve1();
	}
	
}
int main(){
	startTime=clock();
	//int n;
	cin >> n;
	b=new int[n];
	bool flag=true;
	FOR(i,n){
		cin >> b[i];
	}

	if(solve1()){
		for(int i=v.size()-1;i>=0;i--) cout << v[i] <<"\n";
	}
	else{
		cout << -1;
	}
	

	return 0;
}