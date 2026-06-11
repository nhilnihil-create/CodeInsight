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
	string n;
	cin >> n;
	for(int i=0;i<3;i++) if(n[i]=='9') cout << 1; else cout << 9;
	cout << endl;
	return 0;
}