#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll amari = 1e9+7;
#define ben(a) a.begin(),a.end()

int main(){
	vector<int> ab;
	for(int i = 0; i < 6; i++){
		int a;
		cin >> a;
		ab.push_back(a);
	}
	sort(ben(ab));
	int ok = 0;
	for(int i = 0; i < 6; i++){
		if(ab[i] == ab[i + 1])ok++;
		else{
			ok++;
			if(ok == 3){
				cout << "NO" << endl;
				return 0;
			}
			ok = 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}