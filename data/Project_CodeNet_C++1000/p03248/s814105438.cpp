#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

string str;
int N;
void no(){
	cout << "-1\n";
}
bool can(){
	forn(i,1,N){
		if(str[i-1] != str[N-i-1])return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> str;
	N = str.size();
	if(!can() || str[N-1] == '1' || str[0] == '0' || str[N-2] == '0'){
		no();
		return 0;
	}
	int mitad = (N&1) ? (N-1)/2 : N/2;
	int ant = 0;
	int ac = 0;
	int cnt = 1;
	forn(i,1,mitad+1){
		if(str[i-1] == '0')continue;
		int root = cnt;
		while(ac < i){
			cout << root << ' ' << cnt+1 << '\n';
			cnt++;
			ac++;
		}
	}
	int root = cnt; cnt++;
	while(1){
		if(cnt > N)break;
		cout << root << ' ' << cnt << '\n';
		cnt++;
	}
	return 0;
}
/*
__builtin_mul_overflow(x,y,&x)
-fsplit-stack
*/
