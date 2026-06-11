#include<bits/stdc++.h>
using namespace std;
// abc083 A

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a+b == c+d) puts("Balanced");
	else if(a+b > c+d) puts("Left");
	else puts("Right");
}
