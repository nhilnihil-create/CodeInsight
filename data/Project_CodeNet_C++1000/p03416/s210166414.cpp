#include<iostream>
using namespace std;


int isPalindrome(int n)
{
	int rev = 0;
	for (int i = n; i > 0; i /= 10)
		rev = rev*10 + i%10;
	return (n==rev);
}


int countPal(int mn, int mx)
{
	int cnt=0;
	for (int i = mn; i <= mx; i++)
		if (isPalindrome(i)) cnt++;
    return cnt;

}


int main()
{
    int a, b;
    cin>>a>>b;
    int ans;
    ans=countPal(a, b);
    cout<<ans<<endl;
	return 0;
}
