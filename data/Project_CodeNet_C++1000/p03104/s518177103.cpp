
///*Bismillahir Rahmanir Rahim***///
/***Stay_Home_Stay_Safe***/
///**Author Thasin Sheikh**///
#include<bits/stdc++.h>
using namespace std;
#define MAX 35000
#define MOD 1000000007
#define PI 3.14159265359
#define makefast__  ios_base::sync_with_stdio(false);
using ll=long long int  ;
using dl =double;
const int N = 2e5 + 10;
ll aarray[200000+10];
ll magic[101][101];
vector<ll>primes;
bool prime[1000001];
ll cxor(ll n)
{
    if(n%4==0)
        return n;
    if(n%4==1)
        return 1;

    if(n%4==2)
        return n+1;
    else return 0;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    makefast__
    string str;
    ll a,b,c,d,e,f,x,y,k,t,A=0,mod,B=0,L,j,i,l,r,m,n,C=0,ans,sum=0,sum1=0;
    vector<ll>v,v1;
    queue<ll>qu;
    cin>>n>>m;
    ans=cxor(n-1)^cxor(m);
    cout<<ans<<endl;





    return 0;
}