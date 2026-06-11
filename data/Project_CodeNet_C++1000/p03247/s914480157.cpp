#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int main(){
	int n, ans = 0;
	cin >> n;
	vector<int> x(n), y(n);
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	bool f = true;
	int o = (abs(x[0]) + abs(y[0])) % 2;
	for(int i = 1; i < n; i++){
		if((abs(x[i]) + abs(y[i])) % 2 != o){
			f = false;
			break;
		}
	}
	if(f){
		vector<long long> arm;
		if(o == 0) arm.push_back(1);
		for(int i = 0; i < 32; i++){
			arm.push_back(1LL << i);
		}
		cout << arm.size() << endl;
		for(int i = 0; i < arm.size(); i++){
			if(i < arm.size() - 1){
				cout << arm[i] << " ";
			}else{
				cout << arm[i] << endl;
			}
		}
		for(int i = 0; i < n; i++){
			long long a, b;
			a = x[i]; b = y[i];
			string s;
			for(int j = arm.size() - 1; j >= 0; j--){
				long long d = arm[j];
				if(abs(a) >= abs(b)){
					if(a >= 0){
						a -= d;
						s += "R";
					}else{
						a += d;
						s += "L";
					}
				}else{
					if(b >= 0){
						b -= d;
						s += "U";
					} else{
						b += d;
						s += "D";
					}
				}
			}
			reverse(s.begin(), s.end());
			cout << s << endl;
		}
	}else{
		cout << -1 << endl;
	}
	return 0;
}