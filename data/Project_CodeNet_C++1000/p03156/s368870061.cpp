#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin>>n;
	int a,b;
	cin>>a>>b;
	int c[3];
	c[0]=0;
	c[1]=0;
	c[2]=0;
	int i;
	while(n--)
	{
		cin>>i;
		if(i<=a)
		c[0]++;
		else if(i>=b+1)
		c[2]++;
		else
		c[1]++;
	}
	cout<<min(c[0],min(c[1],c[2]));
	return 0;
}

