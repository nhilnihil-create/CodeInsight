#pragma GCC optimize("Ofast,fast-math,unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef string str;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
 
 
 
int main() {
    IOS;
	
	int n;
	cin >> n;
	ll s = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		s+=x;
	}
	cout << s - n;
}