#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string n;

int digitsum(string x){
	int ret = 0;
	rep(i, x.size()) ret += (x[i]-'0');
	return ret;
}

int maxsum(string x){
	int m = x.size();
	if(m == 1) return x[0]-'0';
	int p = x[0]-'0';
	int d = 9*(x.size()-1);
	return max(p+maxsum(x.substr(1)), p-1+d);
}

int main(void){
	cin >> n;
	cout << maxsum(n) << endl;
	return 0;
}
