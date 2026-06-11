#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
#include <math.h>
#include <map>
#include <numeric>
#include <stack>
#include <queue>
#include <functional>
#include <stdio.h>
#define ll long long
#define pl pair<ll,ll>
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vvvl vector<vector<vector<ll> > >
#define vd vector<double>
#define vvd vector<vector<double> >
#define vvvd vector<vector<vector<double> > >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define vvvb vector<vector<vector<bool> > >
#define rep(i,a) for(ll i = 0;i<a;++i)
#define rep1(i,a) for(ll i = 1;i<a;++i)
#define rrep(i,a) for(ll i = a;i>=0;--i)
#define mod 1000000007
#define inf 10010010010
using namespace std;


int main(){
	ll n; cin >> n;
	vl seki(n,0);
	cout << 0 << endl;
	string s;
	cin >> s;
	if (s[0] == 'M') seki[0] = -1;
	else if(s[0] == 'F') seki[0] = 1;
	else return 0;
	rep1(i, n) seki[i] = -seki[i - 1];
	ll left = 1, right = n - 1;
	rep(i, 19){
		ll now = (left + right) / 2;
		cout << now << endl;
		cin >> s;
		if ((s[0] == 'M' && seki[now] != -1) || (s[0] == 'F' && seki[now] != 1)){
			right = now - 1;
		}
		else if (s[0] == 'M' || s[0] == 'F'){
			left = now + 1;
		}
		else return 0;
	}
	return 0;
}