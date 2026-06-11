//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF INT_MAX
#define LLINF LLONG_MAX
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

int main() {
	ll ans = 0;
	ll tmp;
	int n; cin >> n;
	vector<ll> a(n);
	map<ll, int> m;
	REP(i, n){
		cin >> tmp;
		a[i] = tmp;
		m[tmp]++;
	}
	sort(a.rbegin(), a.rend());
	REP(i, n){
		if(m[a[i]]>0){
			ll two = 1 << (int)ceil(log2(a[i]+(ll)1));
			//cout << a[i] << " " << two << endl;
			if((two-a[i] != a[i] && m[two-a[i]]>0) || (two-a[i]==a[i] && m[a[i]] > 1)){
				ans++;
				m[two-a[i]]--;
				m[a[i]]--;
			}
		}	
	}
	cout << ans << endl;
}