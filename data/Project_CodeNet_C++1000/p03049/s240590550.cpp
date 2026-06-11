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
	ll count1=0,count2=0,count=0,count3=0;
	cin >> n;
	string s[n];
	FOR(i,n){
		cin >> s[i];
		FOR(j,s[i].length()-1) if(s[i][j]=='A' && s[i][j+1]=='B') count++;
		if(s[i][0]=='B' && s[i][s[i].length()-1]!='A') count2++;
		if(s[i][s[i].length()-1]=='A' && s[i][0]!='B') count1++;
		if(s[i][0] =='B' && s[i][s[i].length()-1]=='A') count3++;
	}
	
	ll a=min(count2,count1);
	if(count3==0) cout <<count+ a;
	else if(count2+count1 > 0) cout << count+count3+a;
	else cout <<count+ count3-1;
	

	return 0;
}