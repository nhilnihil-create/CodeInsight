#include<bits/stdc++.h>
using namespace std;
stack<int> st;

int main(){
	int n,a,b,x,y,all;
	cin >> n >> a >> b;
	x = n - a;
	y = b - 1;
	if(x <= 0 || y <= 0){
		if(x == 0 && y == 0) for(int i = 1;i <= n;i++) cout << i << ' ';
		else cout << "-1" << endl;
	}
	else if((x % y == 0 && x / y > a) || (x % y != 0 && x / y + 1 > a) || y > x) cout << "-1" << endl;
	else{
		int cnt = a + 1;
		while(--cnt) st.push(cnt);
		all = n - a;
		cnt = n - (b - 2);
		while(true){
			while(cnt <= a) cnt++;
			int ans = cnt;
			for(int i =  1;i <= b - 1 && all >= 1;i++) st.push(ans++),all--;
			if(all <= 0) break;
			cnt -= (b - 1);
			while(cnt <= a) cnt++;
		}
		while(!st.empty()){
			cout << st.top() << ' ';
			st.pop();
		}
	}
}