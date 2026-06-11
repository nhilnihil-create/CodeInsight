#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define sz size
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORN(i,a,b) for(int i=a;i<=b;i++)
#define FORRN(i,a,b) for (int i = (a); i >= (b); i--)
#define FORR(i,a,b) for (int i = (a); i > (b); i--)
typedef unsigned long long ull;
typedef long long ll;

ll n,p;

ll numDivisors(ll p) {
	ll res = 1;
	for (ll i = 2; i * i <= p; ++i) {
		if (p % i == 0) {
			ll cnt = 0;
			while (p % i == 0) { 
				p /= i; 
				++cnt; 
			}
			cnt/=n;
			while(cnt--)
				res*=i;
		}
	}
	return res;
}

int main(){
    ios_base::sync_with_stdio(false); //Fast I/O
    cin.tie(0);
    cout.tie(0);
	//freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);

	cin >> n >> p;

	if(n==1)
		cout << p << endl;
	else
		cout << numDivisors(p) << endl;   

    return 0;
}
