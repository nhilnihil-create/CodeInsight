#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#define llint long long

using namespace std;

llint k;

string tostr(llint x)
{
	char buf[55];
	sprintf(buf, "%lld", x);
	return buf;
}

llint S(llint x)
{
	llint ret = 0;
	for(;x;x/=10) ret += x%10;
	return ret;
}

llint calc(llint x)
{
	string s = tostr(x);
	
	llint mn = x;
	for(int i = 0; i < s.size(); i++){
		for(char j = s[i]; j <= '9'; j++){
			string t;
			for(int k = 0; k < i; k++) t += s[k];
			t += j;
			while(t.size() < s.size()) t += '9';
			llint v = atoll(t.c_str());
			if(v*S(mn) < mn*S(v) || v*S(mn) == mn*S(v) && v < mn) mn = v;
		}
	}
	return mn;
}

int main(void)
{
	cin >> k;
	
	llint ans = 1;
	cout << 1 << endl;
	for(int i = 1; i <= k-1; i++){
		ans = calc(ans+1);
		cout << ans << endl;
	}
	return 0;
}