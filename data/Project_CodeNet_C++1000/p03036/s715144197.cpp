#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll r,d,x; cin >> r >> d >> x;
	for(int i=1;i<=10;i++){
		x *= r;
		x -= d;
		cout << x << endl;
	}
}
