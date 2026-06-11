#include<bits/stdc++.h>
using namespace std;
// abc082 A

#define deb(x) cerr<<"["#x<<" : "<<x<<"]\n";

int main() {
	int a, b;
	cin >> a >> b;
	double k = (a+b)/2.0;
	if(k > int(k)) printf("%d", int(k+1));
	else printf("%d", int(k));
}
