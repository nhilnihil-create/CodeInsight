#include <iostream>
using namespace std;
     
int main()
{
	int n, k;
	cin >> n >> k;
    	
	if ((n - k) >= (k - 1))
    	{
    		cout << "YES" << endl;
    	}
	else
    	{
    		cout << "NO" << endl;
    	}
	return 0;

}
