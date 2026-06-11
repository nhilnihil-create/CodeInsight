#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s;

int main(void){
	cin >> s;
	stack<int> st;
	int ans = 0;
	rep(i, s.size()){
		int c = s[i]-'0';
		int pre = -1;
		if(!st.empty()) pre = st.top();
		if(pre != -1 && pre != c){
			st.pop();
			ans++;
		}else{
			st.push(c);
		}
	}
	cout << 2*ans << endl;
	return 0;
}
