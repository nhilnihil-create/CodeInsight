#include <bits/stdc++.h>
     
using namespace std;

int n,t;
vector <int> a;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;

    for(int i=0;i<n;i++)
    {
    	cin >> t;
    	a.push_back(t);
    }

    if(a[0]!=0)
    {
    	cout << -1 << '\n';
    	return 0;
    }

    long long int res = 0;
    int val = 0;
    for(int i=n-1;i>0;i--)
    {
    	//cout << i << ' ' << val << '\n';
    	if(a[i]-a[i-1] > 1)
    	{
    		cout << -1 << '\n';
    		return 0;
    	}
    	if(a[i]!=0)
    	{
    		if(val < a[i])
    		{
    			res += a[i];
    			val = a[i] - 1;
    		}
    		else
    		{
    			val--;
    		}
    	}
    }

    cout << res << '\n';

    return 0;
}