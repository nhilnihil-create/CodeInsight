#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	string s;
	cin >> s;

	vector<char> a(s.size());
	vector<char> b(s.size());
	for(int i = 0; i < s.size(); i+=2){
		a.at(i) = '1';
		b.at(i) = '0';
	}
	for(int i = 1; i < s.size(); i+=2){
		a.at(i) = '0';
		b.at(i) = '1';
	}

	int diff_a = 0;
	int diff_b = 0;
	rep(i, s.size()){
		if(s.at(i) != a.at(i)){
			diff_a++;
		}else if(s.at(i) != b.at(i)){
			diff_b++;
		}
	}

	cout << min(diff_b, diff_a) << endl;
	return 0;
}