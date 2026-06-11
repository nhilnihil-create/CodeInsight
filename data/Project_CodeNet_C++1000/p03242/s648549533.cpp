#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

#define MAXX 500005

#define PI 3.14159265358979323846264338327950

#define F first
#define S second

#define ll  long long int

#define mod  1000000007



int main()
{
	FAST;
	string s;
	cin >> s;
	for(ll i = 0; i< s.size(); i ++){
		if(s[i] == '9'){
			s[i] = '1';
		}
		else if(s[i] == '1'){
			s[i] = '9';
		}
	}
	cout << s;
}