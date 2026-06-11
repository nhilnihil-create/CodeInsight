// READ & UNDERSTAND
// ll, int overflow, array bounds
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

ll INF=LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	ll a,b; cin >> a >> b;
	int r = b%4;
	if(r==0)b=b;
	else if(r==1)b=1;
	else if(r==2)b++;
	else b=0;
	if(a>0){
		a--;
		r = a%4;
		if(r==0)a=a;
		else if(r==1)a=1;
		else if(r==2)a++;
		else a=0;
	}
	cout << ll(a^b) << endl;
}	
