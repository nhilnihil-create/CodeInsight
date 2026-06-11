#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,a,b;
	cin>>n>>a>>b;
	cout<<min(a,b)<<" "<<max(0,a+b-n)<<endl;
	return 0;
}
