#include <bits/stdc++.h>
#include <string>
using namespace std;
int intinput() {
	int x;
	cin >> x;
	return x;
}
vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	int a,b,c;
	a = intinput();
	b = intinput();
	c = intinput();
	if(c < b){
		cout << c + b << endl;
	}else if(c <= a + b){
		cout << c + b << endl;
	}else{
		cout << a + b*2 + 1 << endl;
	}
}