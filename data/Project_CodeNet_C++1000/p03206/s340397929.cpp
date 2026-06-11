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
	int d;
	cin >> d;
	cout << "Christmas";
	if(d == 25){
		return 0;
	}else{
		for(int i=0;i<25-d;i++) cout << ' ' <<"Eve";
	}
	cout << endl;
	return 0;
}