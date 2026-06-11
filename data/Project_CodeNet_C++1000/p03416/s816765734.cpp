#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a,b;
	cin >> a >> b;
	int counts = 0;
	for(int i = a; i <= b; i++){
		string s = to_string(i);
		if(s[0] == s[4] && s[1] == s[3]) counts++;
	}
	cout << counts << endl;
}