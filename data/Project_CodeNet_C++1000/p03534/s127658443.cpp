#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	cin >> s;
	int a=0,b=0,c=0;
	for (int i=0;i<s.size();i++) {
		if (s[i]=='a') a++;
		else if (s[i]=='b') b++;
		else c++;
	}
	while (a>0&&b>0&&c>0) {
		a--;
		b--;
		c--;
	}
	if ((a==0&&b==0&&c==0)||(a==1&&b==0&&c==0)||(a==1&&b==1&&c==0)||(a==0&&b==1&&c==0)||(a==0&&b==1&&c==1)||(a==0&&b==0&&c==1)||(a==1&&b==0&&c==1)) cout << "YES" << endl; 
	else cout << "NO" << endl;
	return 0;
}