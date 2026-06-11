#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int a,b;
 	cin >> a >> b;
 	if((a*b)&1)
 		cout << "Yes\n";
 	else
 		cout << "No\n";
    return 0;
}