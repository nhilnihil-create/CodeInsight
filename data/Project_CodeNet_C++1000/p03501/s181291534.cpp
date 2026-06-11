#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	     //  #ifndef ONLINE_JUDGE
      //  // for getting input from input.txt
      //  freopen("input.txt", "r", stdin);
      //  // for writing output to output.txt
      //  freopen("output.txt", "w", stdout);
      // #endif
		int n,a,b;
		cin>>n>>a>>b;
		n*a < b? cout<<n*a<<"\n" : cout<<b<<"\n";
	return 0;
}