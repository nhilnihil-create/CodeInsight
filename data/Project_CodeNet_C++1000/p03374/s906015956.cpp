#include<iostream>
#include<cstdio>
#include<math.h>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<map>
#define INF 999999
#define EPS 1.0e-6

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;

int n;
ll c;
ll x[105000];
int v[105000];
ll tokei[105000];
ll hantokei[105000];
ll mx_to[105000];
ll mx_han[105000];

int main()
{
	cin >> n >> c;
	ll xi; int vi;
	for (int i = 1; i <= n; i++) {
		cin >> xi >> vi;
		x[i] = xi; v[i] = vi;
	}
	x[0] = 0; x[n + 1] = c;
	
	tokei[0] = 0;
	for (int i = 1; i <= n; i++) {
		tokei[i] = tokei[i - 1] + v[i] - (x[i] - x[i - 1]);
	}

	hantokei[n+1] = 0;
	for (int i = n; i >=1; i--) {
		hantokei[i] = hantokei[i + 1] + v[i] + (x[i] - x[i + 1]);
	}

	ll tmx = 0;
	ll hmx = 0;
	for (int i = 1; i <= n; i++) {
		tmx = max(tmx, tokei[i]);
		mx_to[i] = tmx;
	}
	for(int i=n+1;i>=1;i--){
		hmx = max(hmx, hantokei[i]);
		mx_han[i] = hmx;
	}

	//tokei->hantokei
	ll thmx = 0;
	for (int i = 0; i <= n; i++) {
		ll iki = tokei[i] - x[i];
		ll cur = iki + mx_han[i + 1];
		thmx = max(thmx, cur);
		//cout << i << " " << iki << " " << mx_han[i + 1] << " " << cur << " " << thmx << endl;
	}

	//hantokei->tokei
	ll htmx = 0;
	for (int i = n + 1; i >= 1; i--) {
		ll iki = hantokei[i] - (c - x[i]);
		ll cur = iki + mx_to[i - 1];
		htmx = max(htmx, cur);

		//cout << i << " " << iki << " " << mx_to[i + 1] << " " << cur << " " << htmx << endl;
	}
	/*
	cout << "tokei[i]:" << " ";
	for (int i = 0; i <= n; i++) {
		cout << tokei[i] << " " ;
	}
	cout << endl;
	cout << "hantokei[i]:" << " ";
	for (int i = n + 1; i >= 1; i--) {
		cout << hantokei[i] << " ";
	}
	cout << endl;
	cout << "mx_to[i]" << " ";
	for (int i = 0; i <= n; i++) {
		cout <<mx_to[i] << " ";
	}
	cout << endl;
	cout << "mx_han[i]" << " ";
	for (int i = n+1; i >= 1; i--) {
		cout << mx_han[i] << " ";
	}
	cout << endl;
	*/
	

	cout << max(thmx,htmx) << endl;


	return 0;
}
