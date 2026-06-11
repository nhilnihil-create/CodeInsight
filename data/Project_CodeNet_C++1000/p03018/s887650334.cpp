
#include<iomanip>
#include<iostream>
#include<string>

using namespace std;

typedef long long int ll;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);

	string s;
	cin >> s;
	string t;
	for (int i = 0; i < s.size();i++){
		if(i+1 < s.size() && s[i] == 'B' && s[i+1] == 'C'){
			t.push_back('D');
			i++;
		}else{
			t.push_back(s[i]);
		}
	}

	ll ans = 0;
	int cnt = 0;
	for (int i = 0; i < t.size();i++){
		if(t[i] == 'A'){
			cnt++;
		}else if(t[i] == 'D'){
			ans += cnt;
		}else{
			cnt = 0;
		}
	}
	cout << ans << endl;

	return 0;
}