#include <bits/stdc++.h>
#define booga cout << "booga" << endl
#define ll long long int
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin >> n >> m;
	if(m % n == 0){
		cout << m/n;
		return 0;
	}
	vector<ll> fac;
	for(ll i{2};i*i < m;i++){
		if(m % i == 0){
			fac.push_back(i);
			if(i >= n){
				cout << m/i;
				return 0;
			}
		}
	}
	int p = fac.size()-1;
	for(int i = p;i >= 0;i--){
		if(m / fac[i] >= n){
			cout << fac[i];
			return 0;
		}
	}
	cout << 1;
	return 0;
}



