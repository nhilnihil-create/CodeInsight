#include <bits/stdc++.h>
using namespace std;
#define pb push_back
long long black , sum , a;
string s;
vector<int>v;
int main(){
	cin >> s;
	sum = 0;
	a = 0;
	black = 0;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == 'B'){
			black++;
			v.pb(i);
		}
	}
	for(int i = v.size() - 1 ; i >= 0 ; i--){
		a++;
		sum += s.size() - v[i] - a;
	}
	cout << sum << endl;
}