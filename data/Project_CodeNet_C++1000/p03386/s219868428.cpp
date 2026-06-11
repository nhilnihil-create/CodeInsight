#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	int a,b,k;
	cin>>a>>b>>k;
	
	for(int i = a; i < min(a+k,b+1); i++)
	{
		cout<<i<<endl;
	}
	for(int i = max(a+k,b-(k-1)); i <= b; i++)
	{
		cout<<i<<endl;
	}
	
	return 0;
}