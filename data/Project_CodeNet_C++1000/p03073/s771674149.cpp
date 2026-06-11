#include <bits/stdc++.h>

using namespace std;
#define sz(a) int(a.size())
#define ll  long long int
#define mod (long long)(1e9+7)
#define endl '\n'
#define ENGZ ios::sync_with_stdio(0);ios_base::sync_with_stdio(0);cin.tie(0) , cout.tie(0) ;
#define pi (acos(-1))
#define F first
#define S second

ll fp(ll n , ll p )
{
    if(p==0)
        return 1;
    if(p==1)
        return n ;
    ll res = fp(n,p/2)%mod ;
    res=((res)*(res))%mod ;
    if(p%2)
        res=(res*n)%mod ;
    return res ;
}


int main()
{
    ENGZ;
    string s ;
    cin>>s ;
    string a = "" , b = "" ;
    for(int i=0 ; i<sz(s) ; i++)
    {
        if(i%2){
            a+="0";
            b+="1";

        }
        else
        {
            a+="1";
            b+="0";
        }
    }
    int ans = 0 , ans1= 0 ;
    for(int i=0 ; i<sz(s) ; i++)
    {
        if(s[i] != a[i])ans++ ;
        if(s[i] != b[i])ans1++ ;
    }
        cout<<min(ans1,ans) <<endl ;


    return 0;
}
