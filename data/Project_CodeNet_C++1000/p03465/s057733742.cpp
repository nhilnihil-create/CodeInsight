#include<bits/stdc++.h>
using namespace std;
bitset<2000005>f;
int main()
{
    f[0]=1;
	int n,a,s=0;
	bool b=0;
    cin>>n;
    while(cin>>a)
    {
        f|=f<<a;
        s+=a;
    }
    for(register int i=int(ceil(s*1.0/2));i<=s;i++)
	{
        if(f[i])
		{
			cout<<i<<endl;
			b=1;
		}
		if(b==1)
			return 0;
    }
    return 0;
}