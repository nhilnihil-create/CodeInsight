#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long a,b,c;
	cin>>a>>b>>c;

	cout<<b+min(a+b+1,c)<<endl;

	return 0;
}
