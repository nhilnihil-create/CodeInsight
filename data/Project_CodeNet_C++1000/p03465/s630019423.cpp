#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+5;
int n,ans;
bitset<maxn> s;
int main(){
    cin>>n;
    s[0]=1;
    for(int i=1,x;i<=n;++i)
	{
        cin>>x;
        s|=s<<x;
        ans+=x;
    }
    for(int i=ans+1>>1;i<=ans;++i)
	{
        if(s[i])
		{
			cout<<i<<endl;
			break;
		}
    }
}