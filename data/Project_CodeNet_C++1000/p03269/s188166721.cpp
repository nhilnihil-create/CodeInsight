#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> PII;

int main() {
	int L;
	cin >> L;

	vector<vector<int>> output;
	for(int i=1; i<20; i++) {
		output.push_back({i, i+1, 0});
	}
	int v = 20;
	int last = 0;
	for(int base=1; base*2 <= L; base*=2, v--) {
		last = base * 2;
		if(v > 0)
			output.push_back({v-1, v, base});
	}
	v = 20;
	for(int base=1; base <=L; base *=2, v--) {
		int k = L;
		for(int i=0; i<20 -v; i++) {
			k/=2;
		}
		if(k%2==0) continue;
		if(last + base <= L) {
			output.push_back({1, v , L - base});
			L -= base;
		}

	}
	cout << 20 <<" " << output.size() <<  endl;
	for(auto data: output) {
		cout << data[0] << " " << data[1] << " " << data[2] << endl;

	}


}


/*
int main() {
	map<int, int> data;
	int iter = 2;
	int L;
	cin >> L;
	for(int i=1; i<=L; i++) {
		int k = i;
		while(k %2 == 0) k/=2;
		int adder = i / k;
		if(adder + i > L) {
			data[i] = iter;
			iter++;
			cout << i << endl;
		}

	} 

	vector<vector<int>> output;
	for(auto val : data) {
		if(val.first == 1) continue;
		int k = val.first;
		while(k%2==0) k/=2;
		int adder = val / k;
		if(adder == val) {
			vector<int> ans;
			ans = {val.second, data[adder/2], 0};
			output.push_back(ans);
			ans = {val.second, data[adder/2], adder}
			output.push_back(ans);
		}
		else {
			vector<int> ans;
			ans = {val.second, data[adder/2 + val.second], adder}
			output.push_back(ans);
			ans = {val.second, data[adder/2], 0}
			output.push_back(ans);
		}
	}
	int maxim = 1;
	for(;maxim < L;) {
		maxim *= 2;
	}
	if(maxim %2 == 0) maxim /= 2;
	output.push_back({1, data[maxim], 0});
	cout << iter + 1 << " " << output.size() + 2 << endl;
	
  return 0;
} 










*/














