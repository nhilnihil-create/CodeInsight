
/**Hey, What's up?*/

#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<long long>v;
int main()
{
    fastio;
    long long a=0,b=0,c,d,e,f=0,l,g,m,n,k,i,j,t,p,q;
    string s;
    cin>>s;
    n=s.size();
    p=0;
    for(i=n-1;i>=0;i--){
        if(s[i]=='W')p++;
        else{
            f+=p;
        }
    }
    cout<<f<<'\n';
    return 0;
}
