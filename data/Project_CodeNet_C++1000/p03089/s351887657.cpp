#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

int main(void){
	cin >> n;
	vector<lli> b(n+1);
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	stack<lli> st;
	while(n > 0 && b[1] == 1){
		for(int i = n; i >= 1; i--){
			if(i == b[i]){
				st.push(b[i]);
				b.erase(b.begin()+i);
				n--;
				break;
			}
		}
	}
	if(n != 0) cout << -1 << endl;
	else{
		while(!st.empty()){
			cout << st.top() << endl;
			st.pop();
		}
	}
	return 0;
}
