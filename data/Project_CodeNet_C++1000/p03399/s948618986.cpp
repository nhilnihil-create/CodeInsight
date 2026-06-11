#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<min(a,b)+min(c,d);
	return 0;
}