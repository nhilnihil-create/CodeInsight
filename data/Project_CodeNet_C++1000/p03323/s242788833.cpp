#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long ll;

using namespace std;

int main()
{
	FastIO;
	int a, b;
	cin >> a >> b;

	if(a > 8 || b > 8) cout << ":(\n";
	else cout << "Yay!\n";
	
	return 0;
}