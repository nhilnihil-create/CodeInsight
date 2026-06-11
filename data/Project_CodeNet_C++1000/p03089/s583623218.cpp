#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> s, tmp, ans;
	for(int i = 0; i < n; ++i){
		int num;
		cin >> num;
		s.push(num);
	}
	while(!s.empty()){
		int num = s.top();
		s.pop();
		if(num == (int)s.size() + 1){
			ans.push(num);
			while(!tmp.empty()){
				s.push(tmp.top());
				tmp.pop();
			}
		}
		else{
			tmp.push(num);
		}
	}
	if(tmp.empty()){
		while(!ans.empty()){
			cout << (ans.top()) << "\n";
			ans.pop();
		}
	}
	else{
		cout << -1;
	}
	return 0;
}
