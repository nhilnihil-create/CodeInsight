#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back

int main()
{	
	string s1, s2;
	cin >> s1 >> s2;
	sort(s1.begin(), s1.end());
	sort(s2.rbegin(), s2.rend());
	
	int n1 = s1.size();
	int n2 = s2.size();
	if(s1 == s2 && n1 < n2) {
		cout << "Yes\n";
	}
	else if(s1<s2) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
