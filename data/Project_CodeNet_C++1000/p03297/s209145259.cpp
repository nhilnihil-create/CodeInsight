#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a,long long int b)
{
	if(a==0)
		return b;
	else
		return gcd(b%a,a);
}

int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        long long int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a<b)
        {
            cout<<"No"<<endl;
            continue;
        }
        if(d<b)
        {
            cout<<"No"<<endl;
            continue;
        }
        c++;
        if(c>=b)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        long long int g=gcd(b,d);
        long long int tmp,tmp2;
        tmp=(a-b)/g;
        tmp2=(a-c)/g;
        tmp2-=tmp;
        if(tmp2<=0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }

    return 0;
}
