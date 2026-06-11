#include <bits/stdc++.h>
using namespace std;

int n;
char s[40];

int main(){
	scanf("%d %s", &n, s);
	
	vector < pair <int, string> > v;
	for(int mask = 0; mask < (1 << n); mask++){
		string a = "", b = "";
		for(int i = 0; i < n; i++){
			if(mask & (1 << i)){
				a += s[i];
			}else{
				b += s[i];
			}
		}

		reverse(b.begin(), b.end());
		a += b;
		
		v.push_back(make_pair(b.size(), a));
	}
	sort(v.begin(), v.end());
	
	long long res = 0;
	for(int mask = 0; mask < (1 << n); mask++){
		string a = "", b = "";
		for(int i = 0; i < n; i++){
			if(mask & (1 << i)){
				a += s[i + n];
			}else{
				b += s[i + n];
			}
		}
		reverse(b.begin(), b.end());
		b += a;
		
		pair <int, string> p = make_pair(a.size(), b);
		res += upper_bound(v.begin(), v.end(), p) - lower_bound(v.begin(), v.end(), p);
	}
	printf("%lld\n", res);
	
	return 0;
}
