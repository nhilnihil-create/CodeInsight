#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 1005;
int x[N], y[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
    	cin >> x[i] >> y[i];
    }

    for (int i = 1; i < n; i++) {
    	if (abs(x[i] + y[i]) % 2 != 
    		abs(x[i - 1] + y[i - 1]) % 2) {
    		cout << -1;
    		return 0;
    	}
    }

    vector<ll> v;

    for (int i = 33; i >= 0; i--) {
    	v.push_back(1ll << i);
    }

    if ((x[0] + y[0]) % 2 == 0) {	
    	v.push_back(1);
    }

    cout << v.size() << "\n";
    for (ll x : v)
    	cout << x << " ";
    cout << "\n";

    for (int j = 0; j < n; j++) {
    	string s;

    	ll a = x[j], b = y[j];

		for (int i = 0; i < v.size(); i++) {
			if (abs(a) > abs(b)) {
				if (a < 0) {
					a += v[i];
					s.push_back('L');
				}
				else {
					a -= v[i];
					s.push_back('R');
				}
			}
			else {
				if (b < 0) {
					b += v[i];
					s.push_back('D');
				}
				else {
					b -= v[i];
					s.push_back('U');
				}
			}
		}

		cout << s << "\n";
	}

    return 0;   
}