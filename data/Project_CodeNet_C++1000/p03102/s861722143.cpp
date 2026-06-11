#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[110], b[110], c, m, n, i, x=0;
    cin>>n>>m>>c;
    for(i=0; i<m; i++)
    	cin>>b[i];
    while(n--)
    {
    	int s=0;
    	for(i=0; i<m; i++)
    	{
    		cin>>a[i];
    		s+=(a[i]*b[i]);
    	}
    	if((s+c)>0)
    		x++;
    }
    cout<<x;
}
    	