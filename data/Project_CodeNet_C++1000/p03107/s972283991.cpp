#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	int count0 = 0;
	int count1 = 0;
	rep(i,(int)s.size()){
		if(s[i] == '1') count1++;
		else if(s[i] == '0') count0++;
	}
	cout << min(count0,count1)*2 << endl;
}

// cout << fixed << setprecision(15) <<  << endl;