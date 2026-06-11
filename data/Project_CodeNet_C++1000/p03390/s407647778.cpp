#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,a,b;
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        int val=(int)sqrt(1ll*a*b);//cout<<"val:  "<<1ll*a*b<<endl;
		int ans=2*(int)sqrt(1ll*a*b)-1;
		if(1ll*val*val==1ll*a*b && a!=b)ans--;
		if(1ll*val*(val+1)>=1ll*a*b)ans--;
		printf("%d\n",ans);

    }
}
