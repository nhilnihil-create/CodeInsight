#include<bits/stdc++.h>
#define reg register
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
string s;
ll ans=inf;
int main(){
    getline(cin,s);
    for(reg int i=0;i<=s.length()-1;i++) 
    if(s[i]!=s[i-1])
    ans=min(ans,max((ll)i,(ll)s.length()-i));
	printf("%lld",min(ans,(ll)s.length()));
    return 0;
}