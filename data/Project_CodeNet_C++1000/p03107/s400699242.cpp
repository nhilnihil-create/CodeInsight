#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	string s; cin>>s;
	deque<char> dq;
	for(auto ch : s){
		if(dq.empty() || dq.back() == ch)dq.push_back(ch);
		else dq.pop_back();
	}
	cout<<s.size() - dq.size()<<endl;

	return 0;
}