#include<iostream>
using namespace std;
bool ispal(int n)
{
	int j=1;

	while(n/j!=0)
		j*=10;
	j/=10;

	while(n!=0)
	{
		if(n/j != n%10)
			return false;
		n=n%j;
		n=n/10;
		j/=100;
	}
	return true;
}

int main()
{
	int a,b,cnt=0;
	cin >> a >> b;

	for( int i=a ; i<=b ; i++ )
		if(ispal(i))
			cnt++;

	cout << cnt << endl;

    return 0;
}