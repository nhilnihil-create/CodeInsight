#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string st;
	cin >> st;
	for(ll i=0; i<8; i++){
		ll cur = 0;
		if(i&(1<<0))
			cur = (st[0]-'0') - (st[1]-'0');
		else
			cur = (st[0]-'0') + (st[1]-'0');
		if(i&(1<<1))
			cur -= (st[2]-'0');
		else
			cur += (st[2]-'0');
		if(i&(1<<2))
			cur -= (st[3]-'0');
		else
			cur += (st[3]-'0');
		if(cur == 7){
			cout << st[0];
			if(i&(1<<0))
				cout << "-";
			else
				cout << "+";
			cout << st[1];
			if(i&(1<<1))
				cout << "-";
			else
				cout << "+";
			cout << st[2];
			if(i&(1<<2))
				cout << "-";
			else
				cout << "+";
			cout << st[3] << "=7";
			return 0;
		}
	}
}