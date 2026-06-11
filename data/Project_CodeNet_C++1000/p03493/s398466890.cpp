#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back

int main()
{	
	string str;
	cin >> str;
	int cnt=0;
	for(int i=0; i<3; i++) {
		if(str[i]=='1') cnt++;
	}
	cout << cnt << endl;
	return 0;
}
