#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
	string s;cin >> s;
	
	int r = 0;
	int b = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '0'){
			r++;
		}else{
			b++;
		}
	}

	cout << min(r,b)*2 << endl;

	return 0;
}
