#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fori(i,n) for(int i=0; i<n; i++)
#define itn int 
#define pb push_back
#define mp make_pair
#define vi vector <int>
#define vll vector <ll>
#define be(a) (a).begin(), (a).end()
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	cout << "2018"; 
	for (int i=4; i<(int)s.size(); i++) {
		cout << s[i];
	} 
	return 0;
}