#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string s;
	cin >> s;
	ll res = s.length()/2, l = s.length()-res, r = res-1;
	char c = s[res];
	while (res<s.length()) {
		res++;
		l--;
		r++;
		if (!(s[l] == c && s[r] == c)) {
			res--;
			break;
		}
	}
	printf("%lld\n",res);
	return 0;
}
