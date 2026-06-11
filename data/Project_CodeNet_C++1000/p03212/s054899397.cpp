#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <climits>
using namespace std;

#define MOD1097 1000000007

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mpair make_pair
#define pm(first, second) pb(mpair(first, second))
#define SPACE " "
#define fpf first.first
#define fps first.second
#define spf second.first
#define sps second.second

#define all(X) (X).begin(), (X).end()
#define reall(X) (X).rbegin(), (X).rend()
#define divcel(a, b) (((a) + ((b) - 1)) / (b))

string next(string S){
	int size = S.size();
	for(int i = 0; i < size; i++){
		if(S[i] == '3'){
			S[i] = '5';
			return S;
		}
		if(S[i] == '5'){
			S[i] = '7';
			return S;
		}
		S[i] = '3';
	}
	S.push_back('3');
	return S;
}
bool is753(string S){
	bool t = false, f = false, s = false;
	int size = S.size();
	for(int i = 0; i < size; i++){
		if(S[i] == '3')t = true;
		else if(S[i] == '5')f = true;
		else if(S[i] == '7')s = true;
	}
	return (t && f && s);
}
int main(){

	ll N;
	cin >> N;
	if(N < 357){
		cout << 0 << endl;
		return 0;
	}
	string S = "553", r;
	ll a, ans = 0;
	while(true){
		S = next(S);
		r = S;
		reverse(r.begin(), r.end());
		a = stoi(r);
		if(a > N)break;
		if(is753(S))ans++;
		//cout << S << endl;
		if(S == "777777777")break;
	}
	cout << ans << endl;

	return 0;
}
