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
string s;
int w=0;
void wrongSolve(){

	ll i=0,j=n-1;
	while(s[i]=='.') i++;
	while(s[j]=='#') j--;
	ll k=i,count1=0,count2=0;
	while(k <=j){
		if(s[k]=='.') count1++;
		if(s[k]=='#') count2++;
		k++;
	}
	cout << min(count2,count1) << "\n";


}


void solve(){
	std::vector<int> white(n+1,0);   
	FOR(i,n){
		white[i]=(s[i]=='.') ? ((i > 0) ? (white[i-1]+1) : 1) : ((i > 0) ?white[i-1] : 0);
	}
	int w=white[n-1];
	int ans=w;
	FOR(i,n){                // last . lies in this position
		if(s[i]=='.') ans=min(ans, (i+1-white[i])+w-white[i] );
		else ans=min(ans,i+1-white[i]+ w-white[i]+1);
	}
	cout << ans;


}


int main(){
	startTime=clock();
	cin >> n;
	cin >> s;	
	solve();
	

	return 0;
}