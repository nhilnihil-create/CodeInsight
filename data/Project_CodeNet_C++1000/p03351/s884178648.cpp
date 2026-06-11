// A - Colorful Transceivers
#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,d; cin>>a>>b>>c>>d;
	if(abs(a-c) <= d) puts("Yes");
	else if(abs(a-b) <= d && abs(b-c) <= d) puts("Yes");
	else puts("No");
}
