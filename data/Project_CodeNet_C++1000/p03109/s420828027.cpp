#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//cout << fixed << setprecision(15);
vector<int> forintinput(int n) {
	vector<int> x;
	for(int i = 0;i < n;i++){
		int ia;
		cin >> ia;
		x.push_back(ia);
	}
	return x;
}
int main(){
	string s;
	cin >> s;
	if((s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+(s[3]-'0') <= 2019){
		if((s[5]-'0')*10+(s[6]-'0') <= 4){
			if((s[8]-'0')*10+(s[9]-'0') <= 30){
				cout << "Heisei" << endl;
				return 0;
			}
		}
	}
	cout << "TBD" << endl;
}