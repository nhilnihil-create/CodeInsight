#include <bits/stdc++.h>
using namespace std;

int n,a,b;
int main() 
{
	cin>>n>>a>>b;
	if(a<b) swap(a,b);
	if((a-b)%2==1) puts("Borys");
	else puts("Alice");
	return 0;
}
