#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, i, r, d;
    cin>>r>>d>>x;
    i=10;
    while(i--)
    {
    	x=(r*x)-d;
    	cout<<x<<endl;
    }
}