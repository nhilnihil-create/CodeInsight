#include<bits/stdc++.h>

using namespace std;

int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d,n;
    cin>>d>>n;
    if(n==100)
    	n++;
   	for(int i=0;i<d;i++)
   	{
   		n=n*100;
   	}
   	cout<<n<<endl;
	return 0;

}