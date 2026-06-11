//Created by Young Charlie
#include <bits/stdc++.h>
using namespace std;
int main() {
	int a,b,c,d; cin>>a>>b>>c>>d;
	cout<<(((abs(a-b) <= d && abs(c-b) <= d) || (abs(c-a) <= d )) ? "Yes\n" : "No\n");
}
