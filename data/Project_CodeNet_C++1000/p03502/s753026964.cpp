#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main()
{
	long long int num,i,j,sum=0;
	
	cin >> num;
	i = num;
	
	for(;num!=0;)
	{
		j = num%10;
		sum+=j;
		num/=10;
	}
	
//	cout << sum;
	
	if(i%sum == 0) cout << "Yes";
	else cout << "No";
}