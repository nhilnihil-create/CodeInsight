#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
int main() {
	string s, ref = "keyence";
	cin >> s;
	int i = 0;
	string sb;
	if (s.size() < ref.size())
		return printf("NO\n"), 0;

	int j = 0;
	if (ref[j] == s[i]) {
		int index = i;
		while (ref[j] == s[index] && j < (int) ref.size()) {
			j++;
			index++;
		}
		if (j == (int) ref.size())
			return printf("YES\n"), 0;

		sb = ref.substr(j);
		//cout << sb << endl;
		string tmp = s.substr(s.size() - sb.size());
		//cout << tmp << endl;
		if (tmp == sb)
			printf("YES\n");
		else
			printf("NO\n");

	}else
		printf("NO\n");

}
