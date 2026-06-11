#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	// #ifndef ONLINE_JUDGE
 //       // for getting input from input.txt
 //       freopen("input.txt", "r", stdin);
 //       // for writing output to output.txt
 //       freopen("output.txt", "w", stdout);
 //      #endif
	int a,t=0,b,sum=0;
	cin>>a>>b;
	if(a ==b) {
		cout<<a+b<<"\n";
	}
	else if(b-a == 1 || a-b == 1){
		cout<<a+b<<"\n";
	}
	else{
		cout<<max(a,b)+(max(a,b)-1)<<"\n";
	}
	return 0;
}