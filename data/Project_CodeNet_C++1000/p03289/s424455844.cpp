#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	string s; cin >> s;
	bool f1=1,f2=0,f3=1;
	int n=s.length();
	if(s[0]!='A')f1=0;
	for(int i=2; i<=n-2; i++){
		if(s[i]=='C'){
			if(f2){
				f2=0;
				break;
			}
			f2=1;
		}
	}
	int cnt = 0;
	for(int i=1; i<n; i++){
		if('A'<=s[i]&&s[i]<='Z'){
			if(s[i]=='C')cnt++;
			else{
				 f3=0; break;
			}
		}
	}
	if(cnt!=1)f2=0,f3=0;
	if(f1&&f2&&f3)cout << "AC";
	else cout << "WA";
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
