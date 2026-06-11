#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define INFLL 0x3f3f3f3f3f3f3f3fLL 
#define EPS 10e-9
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define st first
#define nd second
#define sz(v) int(v.size())
#define all(X) (X).begin(), (X).end()
#define FOR(I, A, B) for(int I = A; I < B; I++)
#define RFOR(I, A, B) for(int I = A; I >= B; I--)

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

int h, w, n, xi, yi;
string s, t;

bool deubom = false;

void build(string &s, string &t ){
	int xu = xi, xd = xi, yl = yi, yr = yi;
	char c;
	FOR(i,0,n){
		c = s[i];
		if(c == 'U'){
			xu--;
			if(xu <= 0)  deubom = true;
		} 
		if(c == 'L'){
			yl--;
			if(yl <= 0) deubom = true;
		} 
		if(c == 'R'){
			yr++;
			if(yr > w) deubom = true;
		} 
		if(c == 'D'){
			xd++;
			if(xd > h) deubom = true;
		}
		c = t[i];
		if(c == 'U'){
			xd--;
			if(xd <= 0) xd++;
		} 
		if(c == 'L'){
			yr--;
			if(yr <= 0) yr++;
		} 
		if(c == 'R'){
			yl++;
			if(yl > w) yl--;
		} 
		if(c == 'D'){
			xu++;
			if(xu > h) xu--;
		}
	}
}

int main(){
	scanf("%d%d%d", &h, &w, &n);
	scanf("%d%d", &xi, &yi);
	cin >> s >> t;

	build(s, t);

	string ans;
	if(deubom){
		ans = "NO\n";
	} else {
		ans = "YES\n";
	}
	cout << ans;

	return 0;
}