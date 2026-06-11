#include <iostream>
using namespace std;

int isPalindrome(int n)
{
    int temp = n;
    int rev = 0;

	while(temp>0)
	{
		rev = 10*rev + temp%10;
		temp /= 10;
	}

	if(rev == n)	return 1;
	else			return 0;
}

int main()
{
	int n,count=0, a, b;
    cin>>a>>b;
	for(int j=a; j<=b; j++)
	{
	    if(isPalindrome(j))
	    {
	        count++;
	    }
	}
	cout<<count<<endl;
	return 0;
}

