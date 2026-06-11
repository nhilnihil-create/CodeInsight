#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define all(x) (x).begin() , (x).end()
#define in insert
#define REP(i,n) for (int i = 1; i <= n; i++)
#define matrix vector<vector<ll> > 
using namespace std;
 
const ll N = 1e5+2;
const ll MOD = 1e9+7;
const ll INF = 1e16;
const ll LOG = 25;
 
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	// ifstream fin ("sound.in");
	// ofstream fout("sound.out");
	string s;
	cin >> s;
	ll n = 1ll*s.size();
	string t;t+= '@';
	t+=s;
	s =t;
	if(s[1] == '0' || s[n] == '1'){
		return cout<<"-1\n",0;
	}
	for(int i =1;i<=n-1;i++){
		if(s[i] != s[n-i]){
			//cout<<i<<' '<<n-i<<endl;
			return cout<<"-1\n",0;
		}
	}
	s[n]='1';	
	//cout<<1ll*v.size()<<endl;
	vector<pll> ans;
	ll nxt = 0;
	for(int i =1;i<n;i++){
		while(nxt <= i || s[nxt] == '0')
			nxt++;
		cout<<nxt<<" "<<i<<endl;
	}

	
	return 0;
}