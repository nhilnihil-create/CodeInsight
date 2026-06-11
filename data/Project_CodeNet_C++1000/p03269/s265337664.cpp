#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
	int l, ans = 0;
	cin >> l;
	int  n = 1, m = 0;
	while((1 << n) <= l) n++;
	vector<int> a(n);
	vector<string> s;
	for(int i = 1; i < n; i++){
		int x = 1 << (i - 1);
		s.push_back(to_string(i) + " " + to_string(i + 1) + " 0");
		s.push_back(to_string(i) + " " + to_string(i + 1) + " " + to_string(x));
		a[i] = a[i - 1] + x;
	}
	int t = a[n - 1] + 1;
	for(int i = n - 1; i >= 0; i--){
		if(a[i] + t <= l - 1){
			s.push_back(to_string(i + 1) + " " + to_string(n) + " " + to_string(t));
			t = a[i] + t + 1;
		}
	}
	m = s.size();
	cout << n << " " << m << endl;
	for(auto&& i : s){
		cout << i << endl;
	}
	return 0;
}