//Created by Young Charlie
#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b; cin>>a>>b;
	int ans = a - 1 + ( b >= a ? 1 : 0);
	cout<<ans<<endl;
}
