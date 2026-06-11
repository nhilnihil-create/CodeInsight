#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int main()
{
    string s,t;
    cin>>s>>t;
    int flag=0;
    int len=s.size();
    for(int i=1;i<=len+1&&!flag;++i){
        if(s==t) flag=1;
        s=s.substr(s.size()-1,1)+s.substr(0,s.size()-1);
        //cout<<s<<endl;
    }
    printf("%s\n",flag?"Yes":"No");

    return 0;
}
