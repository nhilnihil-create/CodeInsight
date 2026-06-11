#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    double n , k ;
	cin >> n >> k;
	double arr[(int)n] , x=0;
	for(int i = 0 ; i  < n ; i++)
    {
        cin >> arr[i];
        if(arr[i]==1)
            x=i;
    }
    cout <<  ceil((n-1)/(k-1)) ;
}
