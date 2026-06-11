#include<bits/stdc++.h>
using namespace std;

int a,b,c,maxy,ans;

int main()
{
	cin>>a>>b>>c;
    maxy = max(max(a,b),c);
    ans = maxy*10 +a+b+c-maxy;
    cout<<ans;
}
