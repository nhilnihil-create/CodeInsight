#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main(){

	string s, t1, t2;
	cin >> s;
	
	rep(i, s.size()) t1+= to_string((i%2) ? 1 : 0 );
	rep(i, s.size()) t2+= to_string(((i+1)%2) ? 1 : 0 );
	
	int cont1 = 0, cont2 = 0;
	rep(i, s.size()) if (s[i] ^ t1[i]) cont1++;
	rep(i, s.size()) if (s[i] ^ t2[i]) cont2++;
	
	printf("%d\n", (cont1 < cont2) ? cont1 : cont2);
	return 0;
}
